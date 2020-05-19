#ifndef passageiro_H
#define passageiro_H
#include<string>
#include<iostream>
using namespace std;
struct passageiro {
	string primeiro_nome;
	string ultimo_nome;
	int n_bilhete;
};
struct nodo_passageiro {
	passageiro dados;
	nodo_passageiro* seguinte;
};
nodo_passageiro* gera_lista_de_espera(string* primeiro_nomes, string* ultimo_nomes, int* n_bilhetes);
nodo_passageiro* insereInicio(nodo_passageiro* inicio, passageiro valor);
nodo_passageiro* criaNo(passageiro valor);
int* gera_lista_bilhetes();
#endif
