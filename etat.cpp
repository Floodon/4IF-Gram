#include "etat.h"
#include "automate.h"


bool Etat0::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->decaler(s,new Etat3());
      return false;
    case PLUS: 
      automate->signalerErreur();
      cout << "Erreur : '+' inattendu" << endl;
      return true;
    case MULT: 
      automate->signalerErreur();
      cout << "Erreur : '*' inattendu" << endl;
      return true;
    case OPENPAR:
      automate->decaler(s,new Etat2());
      return false;
    case CLOSEPAR: 
      automate->signalerErreur();
      cout << "Erreur : ')' inattendu" << endl;
      return true;
    case FIN: 
      automate->signalerErreur();
      cout << "Erreur : 'eof' inattendu" << endl;
      return true;
    case EXPRESSION:
      automate->decaler(s,new Etat1());
      return false;
  }
  return false;
}

bool Etat1::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->signalerErreur();
      cout << "Erreur : 'INT' inattendu" << endl;
      return true;
    case PLUS: 
      automate->decaler(s,new Etat4());
      return false;
    case MULT:
      automate->decaler(s,new Etat5());
      return false;
    case OPENPAR: 
      automate->signalerErreur();
      cout << "Erreur : '(' inattendu" << endl;
      return true;
    case CLOSEPAR: 
      automate->signalerErreur();
      cout << "Erreur : ')' inattendu" << endl;
      return true;
    case FIN:
      return true;
    case EXPRESSION:
      automate->signalerErreur(); 
      cout << "Erreur : 'EXPR' inattendu" << endl;
      return true;
  }
  return false;
}

bool Etat2::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->decaler(s,new Etat3());
      return false;
    case PLUS: 
      automate->signalerErreur();
      cout << "Erreur : '+' inattendu" << endl;
      return true;
    case MULT: 
      automate->signalerErreur();
      cout << "Erreur : '*' inattendu" << endl;
      return true;
    case OPENPAR:
      automate->decaler(s,new Etat2());
      return false;
    case CLOSEPAR: 
      automate->signalerErreur();
      cout << "Erreur : ')' inattendu" << endl;
      return true;
    case FIN: 
      automate->signalerErreur();
      cout << "Erreur : 'eof' inattendu" << endl;
      return true;
    case EXPRESSION:
      automate->decaler(s,new Etat6());
      return false;
  }
  return false;
}

bool Etat3::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->signalerErreur();
      cout << "Erreur : 'INT' inattendu" << endl;
      return true;
    case PLUS: 
      /*reduction 5*/
      automate->reduire(1,s);
      return false;
    case MULT:
      /*reduction 5*/
      automate->reduire(1,s);
      return false;
    case OPENPAR: 
      automate->signalerErreur();
      cout << "Erreur : '(' inattendu" << endl;
      return true;
    case CLOSEPAR:
      /*reduction 5*/
      automate->reduire(1,s);
      return false;
    case FIN:
      /*reduction 5*/
      automate->reduire(1,s);
      return false;
    case EXPRESSION: 
      automate->signalerErreur();
      cout << "Erreur : 'EXPR' inattendu" << endl;
      return true;
  }
  return false;
}

bool Etat4::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->decaler(s,new Etat3());
      return false;
    case PLUS: 
      automate->signalerErreur();
      cout << "Erreur : '+' inattendu" << endl;
      return true;
    case MULT: 
      automate->signalerErreur();
      cout << "Erreur : '*' inattendu" << endl;
      return true;
    case OPENPAR:
      automate->decaler(s,new Etat2());
      return false;
    case CLOSEPAR: 
      automate->signalerErreur();
      cout << "Erreur : ')' inattendu" << endl;
      return true;
    case FIN: 
      automate->signalerErreur();
      cout << "Erreur : 'eof' inattendu" << endl;
      return true;
    case EXPRESSION:
      automate->decaler(s,new Etat7());
      return false;
  }
  return false;
}

bool Etat5::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->decaler(s,new Etat3());
      return false;
    case PLUS: 
      automate->signalerErreur();
      cout << "Erreur : '+' inattendu" << endl;
      return true;
    case MULT: 
      automate->signalerErreur();
      cout << "Erreur : '*' inattendu" << endl;
      return true;
    case OPENPAR:
      automate->decaler(s,new Etat2());
      return false;
    case CLOSEPAR: 
      automate->signalerErreur();
      cout << "Erreur : ')' inattendu" << endl;
      return true;
    case FIN: 
      automate->signalerErreur();
      cout << "Erreur : 'eof' inattendu" << endl;
      return true;
    case EXPRESSION:
      automate->decaler(s,new Etat8());
      return false;
  }
  return false;
}

bool Etat6::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->signalerErreur();
      cout << "Erreur : 'INT' inattendu" << endl;
      return true;
    case PLUS: 
      automate->decaler(s,new Etat4());
      return false;
    case MULT:
      automate->decaler(s,new Etat5());
      return false;
    case OPENPAR: 
      automate->signalerErreur();
      cout << "Erreur : '(' inattendu" << endl;
      return true;
    case CLOSEPAR:
      automate->decaler(s,new Etat9());
      return false;
    case FIN: 
      automate->signalerErreur();
      cout << "Erreur : 'eof' inattendu" << endl;
      return true;
    case EXPRESSION: 
      automate->signalerErreur();
      cout << "Erreur : 'EXPR' inattendu" << endl;
      return true;
  }
  return false;
}

bool Etat7::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->signalerErreur();
      cout << "Erreur : 'INT' inattendu" << endl;
      return true;
    case PLUS: 
      /*reduction 2*/
      automate->reduire(3,s);
      return false;
    case MULT:
      automate->decaler(s,new Etat5());
      return false;
    case CLOSEPAR:
      /*reduction 2*/
      automate->reduire(3,s);
      return false;
    case OPENPAR: 
      automate->signalerErreur();
      cout << "Erreur : '(' inattendu" << endl;
      return true;
    case FIN:
      /*reduction 2*/
      automate->reduire(3,s);
      return false;
    case EXPRESSION: 
      automate->signalerErreur();
      cout << "Erreur : 'EXPR' inattendu" << endl;
      return true;
  }
  return false;
}

bool Etat8::transition(Automate* automate, Symbole * s) {
  switch(*s) {
    case INT: 
      automate->signalerErreur();
      cout << "Erreur : 'INT' inattendu" << endl;
      return true;
    case PLUS: 
      /*reduction 3*/
      automate->reduire(3,s);
      return false;
    case MULT:
      /*reduction 3*/
      automate->reduire(3,s);
      return false;
    case OPENPAR: 
      automate->signalerErreur();
      cout << "Erreur : '(' inattendu" << endl;
      return true;
    case CLOSEPAR:
      /*reduction 3*/
      automate->reduire(3,s);
      return false;
    case FIN:
      /*reduction 3*/
      automate->reduire(3,s);
      return false;
    case EXPRESSION: 
      automate->signalerErreur();
      cout << "Erreur : 'EXPR' inattendu" << endl;
      return true;
  }
  return false;
}


bool Etat9::transition(Automate* automate, Symbole*s) {
  switch(*s) {
    case INT: 
      automate->signalerErreur();
      cout << "Erreur : 'INT' inattendu" << endl;
      return true;
    case PLUS:
      automate->reduire(3,s);
      return false;
    case MULT:
      automate->reduire(3,s);
      return false;
    case OPENPAR: 
      automate->signalerErreur();
      cout << "Erreur : '(' inattendu" << endl;
      return true;
    case CLOSEPAR:
      automate->reduire(3,s);
      return false;
    case FIN:
      /*réduction règle 4*/
      automate->reduire(3,s);
      return false;
    case EXPRESSION: 
      automate->signalerErreur();
      cout << "Erreur : 'EXPR' inattendu" << endl;
      return true;
    }
  return false;
}
