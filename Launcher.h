#include "Pompe.h"
#include "Moteur.h"
#include "Tank.h"
#include "Vanne.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <raylib.h>
#include <string.h>
#include <unistd.h>



class Launcher
{
private:
    Moteur M1,M2,M3;
    Tank T1,T2,T3;
    Vanne V12,V13,V23,VT12,VT23;
    Pompe P1, P1s, P2,P2s,P3,P3s ;
    bool panne;
public:
    Launcher();
    Launcher(const char*);
    void Principal();
    void Alimentation();
    void Transfert();
    bool appui();
    void drawTank();
    void drawInterface();
    void drawMoteur();
    void clic();


    ~Launcher();
};



