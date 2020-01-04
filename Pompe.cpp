#include "Pompe.h"


Pompe::Pompe(){
    etat=false;
}
Pompe::Pompe(bool a){
    etat=a;
}

bool Pompe::getEtat(){
    return etat;
}
void Pompe::setEtat(bool a){
    etat=a;
}

void Pompe::modifEtat(){
    if (getEtat())etat=false;
    else etat=true;
    
}
void Pompe::marche(){
    etat=true;
}
void Pompe::marchepas(){
    etat=false;
}

Pompe::~Pompe(){}