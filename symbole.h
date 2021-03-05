#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION"};

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      bool isTerminal();
      string getEtiquette();
      virtual int getValeur(){return -1;};

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v,int id=INT) : Symbole(id), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur();
   protected:
      int valeur;
};

