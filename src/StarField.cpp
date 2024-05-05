#include "raylib.h"
#include <iostream>

static const int screenWidth = 1280;
static const int screenHeight = 1024;

struct Star
{
    Vector2 position;
    float z; 
};

Vector2 getRandomVec()
{
    float x = GetRandomValue(-screenWidth,screenWidth);
    float y = GetRandomValue(-screenHeight,screenHeight);
    Vector2 res = {x,y}; 
    return res;
}


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "StarField");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
                                    //--------------------------------------------------------------------------------------
                                    //

    int numberOfStars = 100; 

    int zNear = 10;    

    Star stars[600] = {0}; 


    for(int i = 0 ; i < numberOfStars ; i++)
    {
        stars[i].position = getRandomVec();
    }




    //
    //
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


        for(int i = 0 ; i < numberOfStars ; i++)
        {
            stars[i].z += 0.2; 
            if(stars[i].position.x < 0 || stars[i].position.y < 0 ||stars[i].position.x > screenWidth || stars[i].position.y > screenHeight || stars[i].z > zNear)
            {
                stars[i].position = getRandomVec();
                stars[i].z = 0; 
            }
            else
            {
                stars[i].position.x = (stars[i].position.x - (float)screenWidth / 2.0f) * 1.01+ (float)screenWidth / 2.0f;
                stars[i].position.y = (stars[i].position.y - (float)screenHeight / 2.0f) * 1.01 + (float)screenHeight / 2.0f;
            }

        }


        BeginDrawing();

        for(int i = 0 ; i < numberOfStars ; i++)
        {
            DrawCircleV(stars[i].position,stars[i].z,WHITE);        
        }
        ClearBackground(BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
                          //--------------------------------------------------------------------------------------

    return 0;
    }
