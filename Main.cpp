#include "Launcher.h"

int main(int argc, const char** argv) {

    const char* log[3]={"azerty","aa","q"};
    
    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Simulateur");   SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    if (argc==1){
    Launcher L;
    L.Principal();

    }


    else if((strcmp( argv[1], "-ex") == 0)&& argc==3)
    {
        bool verif;
        for (int i = 0; i < 3; i++)
        {
            if(strcmp( argv[2],log[i]) == 0)
            {
                verif=true;
                break;
            }
            else verif=false;
        }
        
        if (verif)
        {
            Launcher L("exo");
            L.Principal(); 
        }
        else cout<<"utilisateur non reconnu"<<endl;
        
        
    }
    else
    {
        cout<<"Option non reconnue\nPour lancer le programme :\n./projet ou ./projet <login>"<<endl;
    }
    
    

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}