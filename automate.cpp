#include "automate.h"
#include "etat.h"
#include "vector"

Automate::Automate(Lexer * l){
  lexer = l;
  Etat * e0 = new Etat0();
  pileEtat.push_back(e0);
  erreur = false;
}

void Automate::analyser() {
  Symbole * s;
  bool end = false;
  while(!end) {
    s=lexer->Consulter();
    end = pileEtat.back()->transition(this, s);
  }
  if(!erreur){
    cout << pileSymbole.back()->getValeur() << endl;
  }
}

void Automate::decaler(Symbole * s, Etat * e) {
   pileEtat.push_back(e);
   pileSymbole.push_back(s);
   if(s->isTerminal()) { 
     lexer->Avancer();
    }
}

void Automate::reduire(int n, Symbole * s){

  vector<Symbole *> chaine;
  for(int i=0;i<n;i++){
    delete(pileEtat.back());
    pileEtat.pop_back();
    chaine.push_back(pileSymbole.back());
    pileSymbole.pop_back();
  }
  int val = -1;
  if(chaine.size()==1){
    val = chaine[0]->getValeur();
  }else{
    if(chaine[1]->getEtiquette()=="PLUS"){
      val = chaine[0]->getValeur()+chaine[2]->getValeur();
    }
    if(chaine[1]->getEtiquette()=="MULT"){
      val = chaine[0]->getValeur()*chaine[2]->getValeur();
    }
    if(chaine[0]->getEtiquette()=="CLOSEPAR"){
      val = chaine[1]->getValeur();
    }
  }
  
  pileEtat.back()->transition(this,new Entier(val,7)); //En tant qu'expression
}

Symbole* Automate::popSymbol(){
  Symbole * last = pileSymbole.back();
  pileSymbole.pop_back();
  return last;
}

void Automate::popAndDestroySymbol(){
  pileSymbole.pop_back();
}

void Automate::signalerErreur(){
  erreur = true;
}
