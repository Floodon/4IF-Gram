#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal(){
  if(ident<6){
    return true;
  }else{
    return false;
  }
}

string Symbole::getEtiquette(){
  return Etiquettes[ident];
}

int Entier::getValeur(){
  return valeur;
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

