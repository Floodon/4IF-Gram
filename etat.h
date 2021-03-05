#include <string>
#include "symbole.h"
using namespace std;

class Automate;

class Etat {
  
 public:
  int num;
  Etat(){};
  virtual ~Etat(){};
  virtual bool transition(Automate* automate, Symbole * s) = 0;
};

class Etat0: public Etat {
  public:
  Etat0(){num = 0;};
  bool transition(Automate* automate, Symbole * s);
};
  
class Etat1: public Etat {
    public:

  Etat1(){num = 1;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat2: public Etat {
    public:

    Etat2(){num = 2;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat3: public Etat {
    public:

    Etat3(){num = 3;};
  bool transition(Automate* automate, Symbole * s);  
};

class Etat4: public Etat {
    public:

    Etat4(){num = 4;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat5: public Etat {
    public:

    Etat5(){num = 5;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat6: public Etat {
    public:

    Etat6(){num = 6;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat7: public Etat {
    public:

    Etat7(){num = 7;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat8: public Etat {
    public:

    Etat8(){num = 8;};
  bool transition(Automate* automate, Symbole * s);
};

class Etat9: public Etat {
    public:

    Etat9(){num = 9;};
  bool transition(Automate* automate, Symbole * s);
};
