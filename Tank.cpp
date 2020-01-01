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

void Tank::marche(){
    etat=true;
}
void Tank::marchepas(){
    etat=false;
}

Tank::~Tank()
{
    //cout <<"destructeur"<< endl;
}
