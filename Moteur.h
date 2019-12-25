#include <iostream>
#include <raylib.h>



using namespace std;



class Moteur
{
private:
    bool etat;
public:
    Moteur();
    void modifEtat();
    void verif();


    ~Moteur();
};

