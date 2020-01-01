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
    bool getEtat();


    ~Pompe();
};
