#pragma once

class Car {
public:
    float x;
    float y;

    Car(float startX, float startY);

    void update(float dt);

    void draw();
};