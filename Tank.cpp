#include "Tank.h"



Tank::Tank(int nbTanks)
{
    this->nbTanks=nbTanks;
    this->capacite=100;
    this->etat=false;
}


int Tank::getCapacite(){
    return capacite;
}

int Tank::getNbTanks(){
    return nbTanks;
}

Tank::~Tank()
{
    //cout <<"destructeur"<< endl;
}
