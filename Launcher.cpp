#include "Launcher.h"

void Principal(){
    Tank a(3);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        drawTank(a);

        drawInterface();

        drawMoteur();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}