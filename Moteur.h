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
    void marche();
    bool getEtat();


    ~Moteur();
};

