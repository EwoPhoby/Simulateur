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

//----------------------------------------------------------------------------------------------------
        //Affichage Pompe
//----------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------
        //Affichage Vidange
//----------------------------------------------------------------------------------------------------
    Rectangle Vidange[3];
    for (int i = 0; i < 3; i++)
    {
        Vidange[i]=Pompe_P[i];
    }
    Vidange[0].x=Pompe_P[1].x+50;
    Vidange[1].x=Pompe_P[3].x+50;
    Vidange[2].x=Pompe_P[5].x+50;

    if(T1.getEtat())DrawRectangleRec(Vidange[0],GREEN);
    else DrawRectangleRec(Vidange[0],RED);

    if(T2.getEtat())DrawRectangleRec(Vidange[1],GREEN);
    else DrawRectangleRec(Vidange[1],RED);

    if(T3.getEtat())DrawRectangleRec(Vidange[2],GREEN);
    else DrawRectangleRec(Vidange[2],RED);

    for (int i = 0; i < 3; i++)
    {
        DrawText("v", Vidange[i].x,Vidange[i].y, 50, WHITE);
    }
    
    
    if (CheckCollisionPointRec(GetMousePosition(), Vidange[0])&& IsGestureDetected(GESTURE_TAP)) 
    T1.setEtat();

    if (CheckCollisionPointRec(GetMousePosition(), Vidange[1])&& IsGestureDetected(GESTURE_TAP)) 
    T2.setEtat();

    if (CheckCollisionPointRec(GetMousePosition(), Vidange[2])&& IsGestureDetected(GESTURE_TAP)) 
    T3.setEtat();
    

    
    

    
//----------------------------------------------------------------------------------------------------
        //Appui sur bouton Pompes
//----------------------------------------------------------------------------------------------------


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


//------------------------------------------------------------------------------------------------------
        //Tuyaux
//------------------------------------------------------------------------------------------------------

    for (int i = 0; i<3; i++)
    {
        DrawLine(375+(250*i),220,375+(250*i),430,BLUE);
    }
    DrawLine((GetScreenWidth()/2)-200+150,Tank_T[0].height,
    (GetScreenWidth()/2)+50,Tank_T[0].height,BLUE);

    DrawLine(Tank_T[2].x,Tank_T[0].height,
    Tank_T[2].x-100,Tank_T[0].height,BLUE);

    DrawLine(375+250,410,375+500,410,BLUE);
    DrawLine(375,300,375+500,300,BLUE);
    DrawLine(375,350,375+250,350,BLUE);
    



//---------------------------------------------------------------------------------------------------
        //Vannes entre Tanks
//---------------------------------------------------------------------------------------------------
    if(VT12.getEtat())DrawCircle(Tank_T[0].x+Tank_T[0].width+50,Tank_T[0].height,20,GREEN);
    else DrawCircle(Tank_T[0].x+Tank_T[0].width+50,Tank_T[0].height,20,RED);

    if(VT23.getEtat())DrawCircle(Tank_T[1].x+Tank_T[1].width+50,Tank_T[1].height,20,GREEN);
    else DrawCircle(Tank_T[1].x+Tank_T[1].width+50,Tank_T[1].height,20,RED);

    DrawText("VT12",485,145,12,BLACK);
    DrawText("VT23",Tank_T[1].x+Tank_T[1].width+40,145,12,BLACK);

//----------------------------------------------------------------------------------------------------
        //Autres Vannes
//----------------------------------------------------------------------------------------------------

    if(V23.getEtat())DrawCircle(755,410,20,GREEN);
    else DrawCircle(755,410,20,RED);

    if(V12.getEtat())DrawCircle(450,350,20,GREEN);
    else DrawCircle(450,350,20,RED);
    
    if(V13.getEtat())DrawCircle(700,300,20,GREEN);
    else DrawCircle(700,300,20,RED);

    DrawText("V23",745,405,12,BLACK);
    DrawText("V12",445,345,12,BLACK);
    DrawText("V13",695,295,12,BLACK);



    




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
//----------------------------------------------------------------------------------------------------
        //Conditions Pour Chaque Moteur et Affichage Etat Marche

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



Launcher::Launcher(const char* a){
    ifstream monFlux(a);  //Ouverture d'un fichier en lecture

if(monFlux)
{
    bool tab[14];
    string id[14];
    
    for (int i = 0; i < 14; i++)
    {
        monFlux >> id[i];
        monFlux >> tab[i];
        cout<<id[i]<<endl;
        cout<<tab[i]<<endl;
    }
    M1.setEtat(tab[0]);
    M2.setEtat(tab[1]);
    M3.setEtat(tab[2]);
    T1.setEtat(tab[3]);
    T2.setEtat(tab[4]);
    T3.setEtat(tab[5]);
    VT12.setEtat(tab[6]);
    VT23.setEtat(tab[7]);
    V12.setEtat(tab[8]);
    V23.setEtat(tab[9]);
    V13.setEtat(tab[10]);
    P1.setEtat(tab[11]);
    P2.setEtat(tab[12]);
    P3.setEtat(tab[13]);
}
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}

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