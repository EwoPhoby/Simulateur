#include <iostream>
#include <raylib.h>



using namespace std;



class tank
{
private:
    int capacite;
    bool etat;
public:
    tank(int);
    int getCapacite();
    void alea();
    void verif();


    ~tank();
};

