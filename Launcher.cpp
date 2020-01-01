#include "Launcher.h"

void Launcher::Principal(){
    

    // Main game loop
    //while (!WindowShouldClose())    // Detect window close button or ESC key
    while (1)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        /*BeginDrawing();

        drawTank();

        drawInterface();

        drawMoteur();

        if(a)cout<<"AAAAAAAPPPPPPPUUUUUUUIIIIIII"<<endl;


        EndDrawing();*/
        //----------------------------------------------------------------------------------
    }
}

void Launcher::Alimentaion(){
    if( 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getCapacite()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getCapacite() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getCapacite() && V13.getEtat()) 
        
    )
    M1.marche();
}

Launcher::Launcher(){
    
}
Launcher::~Launcher(){}