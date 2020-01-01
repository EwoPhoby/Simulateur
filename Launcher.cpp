#include "Launcher.h"

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

void Launcher::Alimentation(){
    if( 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getEtat()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getEtat() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getEtat() && V13.getEtat()) 
        
    )
    M1.marche();
    else M1.marchepas();

    if(M1.getEtat())cout<<"M1 fonctionne"<<endl;
    else cout<<"M1 fonctionne pas"<<endl;
    
    
    

    if( 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getEtat()) || 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getEtat() && V12.getEtat()) || 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getEtat() && V23.getEtat()) 
        
    )
    M2.marche();
    else M2.marchepas();

    if( 
        (( P3.getEtat() || P3s.getEtat() ) && T3.getEtat()) || 
        (( P1.getEtat() || P1s.getEtat() ) && T1.getEtat() && V13.getEtat()) || 
        (( P2.getEtat() || P2s.getEtat() ) && T2.getEtat() && V23.getEtat()) 
        
    )
    M3.marche();
    else M3.marchepas();
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
    Rectangle Tank[3];      // Rectangles array
    
    Rectangle Pompe[6];

    for (int i=0;i<3; i++)
    {
        Tank[i].x=(GetScreenWidth()/2)-200+(250*i);
        Tank[i].y=70;
        Tank[i].width=150;
        Tank[i].height=150;

    }
    for (int i = 0; i<3; i++)    // Draw all rectangles
            {
                DrawRectangleRec(Tank[i],RED);
                
            }
            DrawText("Tank 1", Tank[0].x+50 ,Tank[0].y+(Tank[0].height/2), 20, BLACK);
            DrawText("Tank 2", Tank[1].x+50 ,Tank[1].y+(Tank[1].height/2), 20, BLACK);
            DrawText("Tank 3", Tank[2].x+50 ,Tank[2].y+(Tank[2].height/2), 20, BLACK);



    for (int i = 0; i < 6; i++)
    {
        if (i<2){
            if(i%2==0)Pompe[i].x=Tank[0].x;
            else Pompe[i].x=Tank[0].x+50;
        }
            
        else if (i<4&&i>=2){
            if(i%2==0)Pompe[i].x=Tank[1].x;
            else Pompe[i].x=Tank[1].x+50;
        }
        else if(i>=4)
        {
            if(i%2==0)Pompe[i].x=Tank[2].x;
            else Pompe[i].x=Tank[2].x+50;
        }

        Pompe[i].y=Tank[0].y-50;
        Pompe[i].width=Pompe[i].height=45;
        DrawRectangleRec(Pompe[i],GREEN);

    }

    DrawText("P1", Pompe[0].x,Pompe[0].y, 20, WHITE);
    DrawText("P12", Pompe[1].x,Pompe[1].y, 20, WHITE);
    DrawText("P2", Pompe[2].x,Pompe[2].y, 20, WHITE);
    DrawText("P22", Pompe[3].x,Pompe[3].y, 20, WHITE);
    DrawText("P3", Pompe[4].x,Pompe[4].y, 20, WHITE);
    DrawText("P32", Pompe[5].x,Pompe[5].y, 20, WHITE);
    
    


}

void Launcher::drawMoteur(){

    Rectangle Moteur[3];

    for (int i=0;i<3; i++)
    {
        Moteur[i].x=(GetScreenWidth()/2)-180+(250*i);
        Moteur[i].y=(GetScreenHeight()/2)+75;
        Moteur[i].width=75;
        Moteur[i].height=150;
    }

    for (int i = 0; i<3; i++)
            {
                DrawRectangleRec(Moteur[i],GRAY);
            
            }

    DrawText("M1", Moteur[0].x+Moteur[0].width/2 ,Moteur[0].y+(Moteur[0].height/2), 20, BLACK);
    DrawText("M2", Moteur[1].x+Moteur[1].width/2 ,Moteur[1].y+(Moteur[1].height/2), 20, BLACK);
    DrawText("M3", Moteur[2].x+Moteur[2].width/2 ,Moteur[2].y+(Moteur[2].height/2), 20, BLACK);

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
    
    P1.marche();
    P1s.marchepas();
    T1.marche();

    
}
Launcher::~Launcher(){}