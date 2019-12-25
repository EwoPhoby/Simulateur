#include <iostream>
#include <raylib.h>



using namespace std;



class Tank
{
private:
    int capacite;
    bool etat;
public:
    Tank();
    int getCapacite();
    int getNbTanks();
    void drawTank();


    ~Tank();
};

