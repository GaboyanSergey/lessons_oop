#include "Engine.h"
#include "Car.h"

Car::Car(float startX, float startY) {
    x = startX;
    y = startY;
}

// Движение
void Car::update(float dt) {
    float speed = 300.0f;

    if (is_key_pressed(VK_LEFT)) {
        x -= speed * dt;
    }
    if (is_key_pressed(VK_RIGHT)) {
        x += speed * dt;
    }
    if (is_key_pressed(VK_UP)) {
        y -= speed * dt;
    }
    if (is_key_pressed(VK_DOWN)) {
        y += speed * dt;
    }

    // Проверка границ 
    if (x < 0.0f) x = 0.0f;
    if (x > SCREEN_WIDTH - 144.0f) x = SCREEN_WIDTH - 144.0f;
    if (y < 30.0f) y = 30.0f;
    if (y > SCREEN_HEIGHT - 90.0f) y = SCREEN_HEIGHT - 90.0f;
}

// Отрисовка машины в буфер
void Car::draw() {
    int cx = (int)x;
    int cy = (int)y;

    // car body (red)
    for (int i = cy; i < cy + 60 && i < SCREEN_HEIGHT; i++)
    {
        for (int j = cx; j < cx + 144; j++)
        {
            if (j < SCREEN_WIDTH && i >= 0 && j >= 0)
                buffer[i][j] = 0xcc2222;
        }
    }

    // car top (cabin)
    for (int i = cy - 30; i < cy && i >= 0; i++)
    {
        for (int j = cx + 24; j < cx + 120; j++)
        {
            if (j < SCREEN_WIDTH && j >= 0)
                buffer[i][j] = 0xcc2222;
        }
    }

    // windows (light blue)
    for (int i = cy - 28; i < cy - 5; i++)
    {
        for (int j = cx + 30; j < cx + 65; j++)
        {
            if (j < SCREEN_WIDTH && i >= 0 && j >= 0)
                buffer[i][j] = 0x88ccff;
        }
    }
    for (int i = cy - 28; i < cy - 5; i++)
    {
        for (int j = cx + 75; j < cx + 114; j++)
        {
            if (j < SCREEN_WIDTH && i >= 0 && j >= 0)
                buffer[i][j] = 0x88ccff;
        }
    }

    // wheels (black)
    int wheelY = cy + 52;
    int wheelPositions[] = { cx + 16, cx + 100 };
    for (int w = 0; w < 2; w++)
    {
        for (int i = wheelY; i < wheelY + 28 && i < SCREEN_HEIGHT; i++)
        {
            for (int j = wheelPositions[w]; j < wheelPositions[w] + 24; j++)
            {
                if (j < SCREEN_WIDTH && i >= 0 && j >= 0)
                    buffer[i][j] = 0x111111;
            }
        }
    }

    // wheel hubs (gray)
    int hubPositions[] = { cx + 22, cx + 106 };
    for (int w = 0; w < 2; w++)
    {
        for (int i = wheelY + 8; i < wheelY + 20; i++)
        {
            for (int j = hubPositions[w]; j < hubPositions[w] + 8; j++)
            {
                if (i < SCREEN_HEIGHT && j < SCREEN_WIDTH && i >= 0 && j >= 0)
                    buffer[i][j] = 0x888888;
            }
        }
    }

    // headlights (yellow)
    for (int i = cy + 10; i < cy + 40; i++)
    {
        for (int j = cx + 138; j < cx + 144; j++)
        {
            if (i < SCREEN_HEIGHT && j < SCREEN_WIDTH && i >= 0 && j >= 0)
                buffer[i][j] = 0xffff44;
        }
    }

    // taillights (red-orange)
    for (int i = cy + 10; i < cy + 40; i++)
    {
        for (int j = cx; j < cx + 6; j++)
        {
            if (i < SCREEN_HEIGHT && j < SCREEN_WIDTH && i >= 0 && j >= 0)
                buffer[i][j] = 0xff4400;
        }
    }
}