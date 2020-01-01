#include "Tank.h"



Tank::Tank()
{
    this->capacite=100;
    this->etat=false;
}


int Tank::getCapacite(){
    return capacite;
}

bool Tank::getEtat(){
    return etat;
}
void Tank::setEtat(bool a){
    etat=a;
}
void Tank::setEtat(){}

Tank::~Tank()
{
    //cout <<"destructeur"<< endl;
}
