#include "Tank.h"



Tank::Tank()
{
    this->capacite=100;
    this->etat=false;
}


int Tank::getCapacite(){
    return capacite;
}



Tank::~Tank()
{
    //cout <<"destructeur"<< endl;
}
