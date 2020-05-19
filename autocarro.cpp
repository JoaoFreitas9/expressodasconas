#include <iostream>
#include "autocarro.h"
#include <string>
using namespace std;

string* gera_matricula(char* caracteres) {
	int i = 0;
	string* matricula = new string[];
	while (i < 4) {
		int x = rand() & 35 + 1;
		matricula = matricula + caracteres[x];
		i = i + 1;
	}
	return  matricula;
}
