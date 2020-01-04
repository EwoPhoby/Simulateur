#include <iostream>



using namespace std;



class Pompe
{
private:
    bool etat;
public:
    Pompe();
    Pompe(bool);
    void marche();
    void marchepas();
    void modifEtat();
    void setEtat(bool);
    bool getEtat();


    ~Pompe();
};
