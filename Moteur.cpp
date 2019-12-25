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



Moteur::~Moteur()
{
    //cout <<"destructeur"<< endl;
}
