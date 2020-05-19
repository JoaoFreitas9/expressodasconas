
using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"escritaeleitura.h"
#include"passageiro.h"

int main(){
	srand(time(NULL));
	locale::global(locale(""));
	string* primeiro_nomes = leprimeironome("G:/Users/Rodrigo Silva/Desktop//primeiro_nome.txt");
	string* ultimo_nomes = leultimonome("G:/Users/Rodrigo Silva/Desktop//ultimo_nome.txt");
	string* paragens_nomes = leparagens("G:/Users/Rodrigo Silva/Desktop//paragens.txt");
	int* n_bilhetes = new int[10000];
	int i = 0;
	while (i < 10000) {
		n_bilhetes[i] = i;
		i = i + 1;
	}
	int n_paragens= rand() % 5 + 6;
	char letras[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int numeros[10] = { 0,1,2,3,4,5,6,7,8,9 };
	nodo_passageiro* lista_de_espera = new nodo_passageiro;
	lista_de_espera = gera_lista_de_espera(primeiro_nomes, ultimo_nomes, n_bilhetes);
}
