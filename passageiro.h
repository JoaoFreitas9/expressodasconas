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

struct autocarro {
	int capacidade;
	int quantidade;
	string matricula;
	string condutor;
	nodo_passageiro * utilizadores;
};

void visualizacao(nodo_passageiro* espera);
nodo_passageiro* gera_lista_de_espera(string* primeiro_nomes, string* ultimo_nomes, int* n_bilhetes);
nodo_passageiro* insereInicio(nodo_passageiro* inicio, passageiro valor);
nodo_passageiro* criaNo(passageiro valor);
nodo_passageiro* removefim(nodo_passageiro* head);
int* gera_lista_bilhetes();
string gera_matricula(char* caracteres);
autocarro gera_autocarro(nodo_passageiro* lista_de_espera, int& n_passageiros_lista_espera, char* caracteres);
#endif
