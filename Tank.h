#include <iostream>



using namespace std;



class Tank
{
private:
    int capacite;
    bool etat;
public:
    Tank();
    int getCapacite();
    bool getEtat();
    void setEtat();
    void setEtat(bool);
    int getNbTanks();
    void drawTank();


    ~Tank();
};

