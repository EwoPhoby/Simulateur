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
    void setEtat(bool);
    void marche();
    void marchepas();
    bool getEtat();


    ~Moteur();
};

