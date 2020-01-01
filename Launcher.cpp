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


        EndDrawing();*/
        //----------------------------------------------------------------------------------
    }
}

void Launcher::Alimentation(){
    if( 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getCapacite()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getCapacite() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getCapacite() && V13.getEtat()) 
        
    )
    M1.marche();
    else M1.marchepas();
    
    

    if( 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getCapacite()) || 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getCapacite() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getCapacite() && V23.getEtat()) 
        
    )
    M2.marche();
    else M2.marchepas();

    if( 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getCapacite()) || 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getCapacite() && V13.getEtat()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getCapacite() && V23.getEtat()) 
        
    )
    M3.marche();
    else M3.marchepas();
}









Launcher::Launcher(){
    
}
Launcher::~Launcher(){}