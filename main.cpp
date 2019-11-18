#include "raylib.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Simulateur");

    Rectangle Tank[3];      // Rectangles array
    Rectangle Moteur[3];

    

    for (int i = 0; i < 3; i++)
    {
        Tank[i].x=100 + 220*i;
        Tank[i].y=70;
        Tank[i].width=150;
        Tank[i].height=150;
    }

    for (int i = 0; i<3; i++)
    {
        Moteur[i].x=75+ 280*i;
        Moteur[i].y=GetScreenHeight()-160;
        Moteur[i].width=75;
        Moteur[i].height=150;
    }
    
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            
            for (int i = 0; i<3; i++)    // Draw all rectangles
            {
                DrawRectangleRec(Tank[i],RED);
                DrawRectangleRec(Moteur[i],GRAY);

            }

            DrawText("Tank 1", Tank[0].x+50 ,Tank[0].y+(Tank[0].height/2), 20, BLACK);
            DrawText("Tank 2", Tank[1].x+50 ,Tank[1].y+(Tank[1].height/2), 20, BLACK);
            DrawText("Tank 3", Tank[2].x+50 ,Tank[2].y+(Tank[2].height/2), 20, BLACK);

            


            


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}