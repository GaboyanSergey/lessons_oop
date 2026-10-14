#include "Engine.h"
#include "Sky.h"

Sky::Sky() {

}

// Метод отрисовки фона в буфер
void Sky::draw() {
    // sky background
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            buffer[i][j] = 0x4477aa;
        }
    }

    // road
    int roadY = 580;
    for (int j = 0; j < SCREEN_WIDTH; j++)
    {
        for (int i = roadY; i < roadY + 120; i++)
        {
            if (i < SCREEN_HEIGHT)
                buffer[i][j] = 0x555555;
        }
    }

    // road lines
    for (int j = 0; j < SCREEN_WIDTH; j += 80)
    {
        for (int dj = 0; dj < 40; dj++)
        {
            if (j + dj < SCREEN_WIDTH)
                buffer[roadY + 60][j + dj] = 0xffffff;
        }
    }
}