#include "Launcher.h"

void Principal(){
    Tank a();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        drawTank();

        drawInterface();

        drawMoteur();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}