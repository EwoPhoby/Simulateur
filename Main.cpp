#include "Launcher.h"

int main(int argc, const char** argv) {
    
    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 700;

    //InitWindow(screenWidth, screenHeight, "Simulateur");   SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    if (argc==1){
    Launcher L;
    L.Principal();}


    else cout<<"Pas Encore Implemente"<<endl;

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}