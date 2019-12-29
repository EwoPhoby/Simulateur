#include <iostream>



using namespace std;



class Moteur
{
private:
    bool etat;
public:
    Moteur();
    Moteur(bool);
    void modifEtat();
    bool getEtat();


    ~Moteur();
};

