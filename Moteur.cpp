#include "Moteur.h"



Moteur::Moteur()
{
    etat=false;   
}

Moteur::Moteur(bool a)
{
    etat=a;
}


bool Moteur::getEtat(){
    return etat;
}

void Moteur::modifEtat(){
    if (getEtat()) etat=false;
    else etat=true;
}

void Moteur::setEtat(bool a){
    etat=a;
}

void Moteur::marche(){etat=true;}
void Moteur::marchepas(){etat=false;}



Moteur::~Moteur()
{
    //cout <<"destructeur"<< endl;
}
