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
    void setEtat(bool);
    bool getEtat();


    ~Vanne();
};
