#include <iostream>
#include <raylib.h>



using namespace std;



class Tank
{
private:
    int nbTanks;
    int capacite;
    bool etat;
public:
    Tank(int);
    int getCapacite();
    int getNbTanks();
    void drawTank();


    ~Tank();
};

