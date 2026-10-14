/* MIT License
 * 
 * Copyright (c) 2026 Voronezh State University
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _DEFAULT_SOURCE

#include "Engine.h"
#include "Car.h"
#include "Sky.h"
#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <ctime>
#include <cstdarg>
#include <cstdio>

Car* car = nullptr; // Указатель на машину
Sky* sky = nullptr; // Указатель на фон

// initialize game data in this function
void initialize()
{
    sky = new Sky();          // Создаем фон
    car = new Car(440, 540);  // Машина в начальной позиции
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    if (car != nullptr) {
        car->update(dt);
    }
}

// fill buffer in this function
// uint32_t buffer[SCREEN_WIDTH][SCREEN_HEIGHT] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
    if (sky != nullptr) {
        sky->draw();
    }

    if (car != nullptr) {
        car->draw();
    }
}

// free game data in this function
void finalize()
{
    if (car != nullptr) {
        delete car;
        car = nullptr;
    }
    if (sky != nullptr) {
        delete sky;
        sky = nullptr;
    }
}
