#include "Afficher.h"

void drawTank(Tank a){
    Rectangle Tank[a.getNbTanks()];      // Rectangles array
        

    for (int i=0;i<a.getNbTanks(); i++)
    {
        Tank[i].x=100 + 220*i;
        Tank[i].y=70;
        Tank[i].width=150;
        Tank[i].height=150;
    }



    for (int i = 0; i<a.getNbTanks(); i++)    // Draw all rectangles
            {
                DrawRectangleRec(Tank[i],RED);
                

            }

            DrawText("Tank 1", Tank[0].x+50 ,Tank[0].y+(Tank[0].height/2), 20, BLACK);
            DrawText("Tank 2", Tank[1].x+50 ,Tank[1].y+(Tank[1].height/2), 20, BLACK);
            DrawText("Tank 3", Tank[2].x+50 ,Tank[2].y+(Tank[2].height/2), 20, BLACK);


}

void drawInterface(){

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
        

    }    
}



