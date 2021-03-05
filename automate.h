#include <iostream>
#include <deque>
#include "symbole.h"
#include "lexer.h"
class Etat;
class Etat0;
class Symbole;
class Lexer;

class Automate {
  protected : 
    deque<Etat*> pileEtat;
    deque<Symbole*> pileSymbole;
    Lexer * lexer;
    bool erreur;

  public :
    Automate(Lexer * l);
    void analyser();
    void decaler(Symbole * s, Etat * e);
    void reduire(int n, Symbole * s);
    int calculer(Symbole * s);
    int getTetePileEtat();
    void popAndDestroySymbol();
    Symbole* popSymbol();
    void signalerErreur();
};