#include "Moteur.h"



Moteur::Moteur()
{
    etat=true;   
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

void Moteur::marche(){etat=true;}
void Moteur::marchepas(){etat=false;}



Moteur::~Moteur()
{
    //cout <<"destructeur"<< endl;
}
