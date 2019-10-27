#include "tank.h"

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
tank::~tank()
{
    cout <<"destructeur"<< endl;
}
