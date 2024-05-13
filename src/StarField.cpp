#include "raylib.h"
#include <iostream>

static const int screenWidth = 1280;
static const int screenHeight = 1024;
static const float zFar = 10.0;    
static const float zNear = 0.1;    
static const int offsetX = screenWidth / 2;
static const int offsetY = screenHeight / 2;
static const int numberOfStars = 300;

struct Star
{
    Vector3 position;
};

Vector3 getRandomVec()
{
    float x = GetRandomValue(-screenWidth,screenWidth);
    float y = GetRandomValue(-screenHeight,screenHeight);
    float z = GetRandomValue(zNear,zFar);
    Vector3 res = {x,y,z}; 
    return res;
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "StarField");

    SetTargetFPS(60);               


    Star stars[numberOfStars] = {0}; 


    for(int i = 0 ; i < numberOfStars ; i++)
    {
        stars[i].position = getRandomVec();
    }

    while (!WindowShouldClose())    
    {

        BeginDrawing();
        for(int i = 0 ; i < numberOfStars ; i++)
        {
            float z = stars[i].position.z;

            z -= 0.1; // control speed
            if(z <= zNear) 
            {
                stars[i].position = getRandomVec();
                z = stars[i].position.z;
            }

            float x = stars[i].position.x;
            float y = stars[i].position.y;

            float dX = x / z + offsetX; 
            float dY = y / z + offsetY; 

            DrawCircle(dX,dY,5/z,WHITE);
            stars[i].position.z = z;

        }

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
                          //--------------------------------------------------------------------------------------

    return 0;
}
