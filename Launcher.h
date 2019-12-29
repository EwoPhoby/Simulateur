#include "Afficher.h"


class Launcher
{
private:
    Moteur M1,M2,M3;
    Tank T1,T2,T3;
    Vanne V1;
    Pompe P1;
    bool panne;
public:
    Launcher();
    void Principal();


    ~Launcher();
};



