#include "Launcher.h"


Rectangle Tank_T[3];      // Rectangles array
Rectangle Pompe_P[6];
Rectangle Moteur_M[3];

void Launcher::Principal(){
    

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

        Alimentation();

        Transfert();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}




void Launcher::Transfert(){
    
    if(VT12.getEtat()){        
        if(T1.getEtat())    T2.setEtat(T1.getEtat());   //verif et remplissage
        else if (T2.getEtat())  T1.setEtat(T2.getEtat());
    }
    if(VT23.getEtat()){        
        if(T2.getEtat())    T3.setEtat(T2.getEtat());   //verif et remplissage
        else if (T3.getEtat())  T2.setEtat(T3.getEtat());
    }
}

void Launcher::drawTank(){
    

    for (int i=0;i<3; i++)
    {
        Tank_T[i].x=(GetScreenWidth()/2)-200+(250*i);
        Tank_T[i].y=70;
        Tank_T[i].width=150;
        Tank_T[i].height=150;

    }
    for (int i = 0; i<3; i++)    // Draw all rectangles
            {
                DrawRectangleRec(Tank_T[i],RED);
                
            }
            DrawText("Tank 1", Tank_T[0].x+50 ,Tank_T[0].y+(Tank_T[0].height/2), 20, BLACK);
            DrawText("Tank 2", Tank_T[1].x+50 ,Tank_T[1].y+(Tank_T[1].height/2), 20, BLACK);
            DrawText("Tank 3", Tank_T[2].x+50 ,Tank_T[2].y+(Tank_T[2].height/2), 20, BLACK);



    for (int i = 0; i < 6; i++)
    {
        if (i<2){
            if(i%2==0)Pompe_P[i].x=Tank_T[0].x;
            else Pompe_P[i].x=Tank_T[0].x+50;
        }
            
        else if (i<4&&i>=2){
            if(i%2==0)Pompe_P[i].x=Tank_T[1].x;
            else Pompe_P[i].x=Tank_T[1].x+50;
        }
        else if(i>=4)
        {
            if(i%2==0)Pompe_P[i].x=Tank_T[2].x;
            else Pompe_P[i].x=Tank_T[2].x+50;
        }

        Pompe_P[i].y=Tank_T[0].y-50;
        Pompe_P[i].width=Pompe_P[i].height=45;
        DrawRectangleRec(Pompe_P[i],GREEN);

    }

    DrawText("P1", Pompe_P[0].x,Pompe_P[0].y, 20, WHITE);
    DrawText("P12", Pompe_P[1].x,Pompe_P[1].y, 20, WHITE);
    DrawText("P2", Pompe_P[2].x,Pompe_P[2].y, 20, WHITE);
    DrawText("P22", Pompe_P[3].x,Pompe_P[3].y, 20, WHITE);
    DrawText("P3", Pompe_P[4].x,Pompe_P[4].y, 20, WHITE);
    DrawText("P32", Pompe_P[5].x,Pompe_P[5].y, 20, WHITE);
    
    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[0])&& IsGestureDetected(GESTURE_TAP)) 
    P1.modifEtat();
    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[1])&& IsGestureDetected(GESTURE_TAP))
    P1s.modifEtat(); 
    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[2])&& IsGestureDetected(GESTURE_TAP)) 
    P2.modifEtat();
    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[3])&& IsGestureDetected(GESTURE_TAP)) 
    P2.modifEtat();
    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[4])&& IsGestureDetected(GESTURE_TAP)) 
    P3.modifEtat();
    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[5])&& IsGestureDetected(GESTURE_TAP)) 
    P3s.modifEtat();




}

void Launcher::drawMoteur(){

    for (int i=0;i<3; i++)
    {
        Moteur_M[i].x=(GetScreenWidth()/2)-180+(250*i);
        Moteur_M[i].y=(GetScreenHeight()/2)+75;
        Moteur_M[i].width=75;
        Moteur_M[i].height=150;
    }

    for (int i = 0; i<3; i++)
            {
                DrawRectangleRec(Moteur_M[i],GRAY);
            
            }

    DrawText("M1", Moteur_M[0].x+Moteur_M[0].width/2 ,Moteur_M[0].y+(Moteur_M[0].height/2), 20, BLACK);
    DrawText("M2", Moteur_M[1].x+Moteur_M[1].width/2 ,Moteur_M[1].y+(Moteur_M[1].height/2), 20, BLACK);
    DrawText("M3", Moteur_M[2].x+Moteur_M[2].width/2 ,Moteur_M[2].y+(Moteur_M[2].height/2), 20, BLACK);

}

void Launcher::Alimentation(){
    if( 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getEtat()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getEtat() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getEtat() && V13.getEtat()) 
        
    )
    M1.marche();
    else M1.marchepas();

    if(M1.getEtat())DrawCircle(Moteur_M[0].x+Moteur_M[0].width/2, Moteur_M[0].y+20,19,GREEN);
    else DrawCircle(Moteur_M[0].x+Moteur_M[0].width/2, Moteur_M[0].y+20,19,RED);
    
    
    

    if( 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getEtat()) || 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getEtat() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getEtat() && V23.getEtat()) 
        
    )
    M2.marche();
    else M2.marchepas();

    if(M2.getEtat())DrawCircle(Moteur_M[1].x+Moteur_M[1].width/2, Moteur_M[1].y+20,19,GREEN);
    else DrawCircle(Moteur_M[1].x+Moteur_M[1].width/2, Moteur_M[1].y+20,19,RED);
    
    if( 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getEtat()) || 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getEtat() && V13.getEtat()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getEtat() && V23.getEtat()) 
        
    )
    M3.marche();
    else M3.marchepas();

    if(M3.getEtat())DrawCircle(Moteur_M[2].x+Moteur_M[2].width/2, Moteur_M[2].y+20,19,GREEN);
    else DrawCircle(Moteur_M[2].x+Moteur_M[2].width/2, Moteur_M[2].y+20,19,RED);
    
}

void Launcher::drawInterface(){

    const char *nomBouton[8] = {
        "VT1", "VT2", "P12", "P22", "P32", "V12", "V13", "V23"};

    Rectangle bouton[8] = { 0 };     // Rectangles array

    // Fills bouton data (for every rectangle)
    for (int i = 0; i < 8; i++)
    {
        bouton[i].x =GetScreenWidth()/20;
        bouton[i].y = ((GetScreenHeight()/11)*i)+(10*i)+GetScreenHeight()/11;

        bouton[i].width = GetScreenWidth()/5;
        bouton[i].height = GetScreenHeight()/12;


        DrawRectangleRec(bouton[i], BLACK);
        DrawRectangleLinesEx(bouton[i], 6, Fade(BLUE, 0.3f));

        DrawText(nomBouton[i], bouton[i].x + bouton[i].width/2 - MeasureText(nomBouton[i], 25) - 12,
                             bouton[i].y + bouton[i].height/2 , 30,WHITE);
        

        

        //Verification appui bouton interface
        for (int i = 0; i < 8; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), bouton[i])&& IsGestureDetected(GESTURE_TAP)) 
                {
                    DrawCircle(GetScreenWidth(),GetScreenHeight()/2,50,BLUE);
                    V12.modifEtat();
                    //break;

                    //faire des if avec le methodes implementees ptet avec des enum de i	
                }
            
            
            
        }

    }    
}





Launcher::Launcher(){
    
    
    T1.marche();
    T2.marche();
    T3.marche();

    
}
Launcher::~Launcher(){}