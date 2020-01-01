#include "Launcher.h"


Rectangle Tank_T[3];      // Rectangles array
Rectangle Pompe_P[6];
Rectangle Moteur_M[3];
const char* text[6]={"P1","P12","P2","P22","P3","P32"};


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
        //DrawRectangleRec(Pompe_P[i],GREEN);

    }

    if(P1.getEtat())DrawRectangleRec(Pompe_P[0],GREEN);
    else DrawRectangleRec(Pompe_P[0],RED);

    if(P1s.getEtat())DrawRectangleRec(Pompe_P[1],GREEN);
    else DrawRectangleRec(Pompe_P[1],RED);

    if(P2.getEtat())DrawRectangleRec(Pompe_P[2],GREEN);
    else DrawRectangleRec(Pompe_P[2],RED);

    if(P2s.getEtat())DrawRectangleRec(Pompe_P[3],GREEN);
    else DrawRectangleRec(Pompe_P[3],RED);
    
    if(P3.getEtat())DrawRectangleRec(Pompe_P[4],GREEN);
    else DrawRectangleRec(Pompe_P[4],RED);

    if(P3s.getEtat())DrawRectangleRec(Pompe_P[5],GREEN);
    else DrawRectangleRec(Pompe_P[5],RED);

for (int i = 0; i < 6; i++)
{
    DrawText(text[i], Pompe_P[i].x,Pompe_P[i].y, 20, WHITE);
}

    
//1 sur 2 car interface 2 pour reparation


    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[0])&& IsGestureDetected(GESTURE_TAP)) 
    P1.modifEtat();

    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[1])&& IsGestureDetected(GESTURE_TAP))
    P1s.modifEtat(); 

    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[2])&& IsGestureDetected(GESTURE_TAP)) 
    P2.modifEtat();

    if (CheckCollisionPointRec(GetMousePosition(), Pompe_P[3])&& IsGestureDetected(GESTURE_TAP)) 
    P2s.modifEtat();

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
        "VT12", "VT23", "P12", "P22", "P32", "V12", "V13", "V23"};

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
    }

    if(VT12.getEtat())DrawCircle(Tank_T[0].x+Tank_T[0].width+50,Tank_T[0].height,20,GREEN);
    else DrawCircle(Tank_T[0].x+Tank_T[0].width+50,Tank_T[0].height,20,RED);

    if(VT23.getEtat())DrawCircle(Tank_T[1].x+Tank_T[1].width+50,Tank_T[1].height,20,GREEN);
    else DrawCircle(Tank_T[1].x+Tank_T[1].width+50,Tank_T[1].height,20,RED);


        
//-------------------------------------------------------------------------------------------------
        //Appui bouton interface
//-------------------------------------------------------------------------------------------------
       
        if (CheckCollisionPointRec(GetMousePosition(), bouton[0])&& IsGestureDetected(GESTURE_TAP)) 
        VT12.modifEtat();

        if (CheckCollisionPointRec(GetMousePosition(), bouton[1])&& IsGestureDetected(GESTURE_TAP))
        VT23.modifEtat();

        if (CheckCollisionPointRec(GetMousePosition(), bouton[2])&& IsGestureDetected(GESTURE_TAP)) 
        P1s.modifEtat();	
        
        if (CheckCollisionPointRec(GetMousePosition(), bouton[3])&& IsGestureDetected(GESTURE_TAP)) 
        P2s.modifEtat();

        if (CheckCollisionPointRec(GetMousePosition(), bouton[4])&& IsGestureDetected(GESTURE_TAP)) 
        P3s.modifEtat();

        if (CheckCollisionPointRec(GetMousePosition(), bouton[5])&& IsGestureDetected(GESTURE_TAP)) 
        V12.modifEtat();

        if (CheckCollisionPointRec(GetMousePosition(), bouton[6])&& IsGestureDetected(GESTURE_TAP)) 
        V13.modifEtat();
            
        if (CheckCollisionPointRec(GetMousePosition(), bouton[7])&& IsGestureDetected(GESTURE_TAP)) 
        V23.modifEtat();
}

Launcher::Launcher(){
    T1.marche();
    T2.marche();
    T3.marche();
    P1.marche();
    P2.marche();
    P3.marche();

}
Launcher::~Launcher(){
    cout<<"Fin et destruction"<<endl;
}