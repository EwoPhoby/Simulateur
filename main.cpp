#include "tank.h"
#include <raylib.h>

int main(int argc, const char** argv) {
    
    //cout << "message" << endl;

    InitWindow(500,500,"test");

    tank t(5);
    t.verif();

    
    //fenetre raylib
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLUE);//

           

        EndDrawing();
    }
    CloseWindow();
    //return 0;
}