#include "automate.h"
#include "lexer.h"
#include <iostream>

int main(void) {
	string chaine("(1+34)*123");
	Lexer l(chaine);
	Automate automate(&l);
	Symbole *s;
	automate.analyser();
	return 0;
}
