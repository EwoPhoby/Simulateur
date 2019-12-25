#include "Vanne.h"

Vanne::Vanne(){
    etat=false;
}
Vanne::Vanne(bool a){
    etat=a;
}

bool Vanne::getEtat(){
    return etat;
}

void Vanne::modifEtat(){
    if (getEtat())etat=false;
    else etat=true;
    
}