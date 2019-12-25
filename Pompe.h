#include <iostream>
#include <raylib.h>



using namespace std;



class Pompe
{
private:
    bool etat;
public:
    Pompe();
    Pompe(bool);
    void modifEtat();
    bool getEtat();


    ~Pompe();
};
