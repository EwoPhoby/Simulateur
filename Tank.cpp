#include "Tank.h"



Tank::Tank()
{
    this->capacite=100;
    this->etat=true;
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

void Tank::setEtat(){
    if (etat==true)etat=false;
    else etat=true;
}

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
