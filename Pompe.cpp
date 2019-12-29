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

void Pompe::modifEtat(){
    if (getEtat())etat=false;
    else etat=true;
    
}

Pompe::~Pompe(){}