#include "Afficher.h"


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
    void Principal();
    void Alimentaion();


    ~Launcher();
};



