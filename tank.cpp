#include "tank.h"
#include <time.h>

//srand();

tank::tank(int capacite)
{
    this->capacite=capacite;
    this->etat=false;
}
void tank::verif()
{
    if(etat==true)cout <<"capacite="<<capacite<< endl;
    if(etat==false)cout <<"erreur"<< endl;
}

int tank::getCapacite(){
    return capacite;
}

void tank::alea(){
    
    this->capacite=GetRandomValue(5,10);

}

tank::~tank()
{
    cout <<"destructeur"<< endl;
}
