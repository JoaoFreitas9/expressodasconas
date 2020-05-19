#ifndef AUTOCARRO_H
#define AUTOCARRO_H
#include<string>
#include<iostream>
using namespace std;

struct autocarro {
	int capacidade;
	int quantidade;
	string matricula;
	string condutor;
};

string* gera_matricula(char* caracteres);
#endif
