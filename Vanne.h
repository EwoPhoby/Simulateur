#include <iostream>



using namespace std;



class Vanne
{
private:
    bool etat;
public:
    Vanne();
    Vanne(bool);
    void modifEtat();
    bool getEtat();


    ~Vanne();
};
