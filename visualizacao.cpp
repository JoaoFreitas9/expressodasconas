#include <iostream>
#include <string>
#include "passageiro.h"
#include <iomanip> 

using namespace std;

void visualizacao(autocarro*bus, int n_paragens, autocarro *head, nodo_passageiro*espera) 
{

		cout << "Fila de Espera:" << endl;
		int a = 0;
		nodo_passageiro* temp = espera;
		while (temp->seguinte != NULL) {
			a = a + 1;
			temp = temp->seguinte;
		}
		int colunas;
		int filas;
		if (a % 3 == 0) {
			colunas = 3;
			filas = a/3;
		}
		else {
			colunas = 3;
			filas = (int)(a / 3) + 1;
		}
		for (int x = colunas; x < x + 1; x++) {
			for (int y = filas; y = y + 1; y++) {
				cout << setw(11) << espera->dados.ultimo_nome << endl;
				espera = espera->seguinte;
			}
		}
		for (int x = 0; x < n_paragens; x++) {
			cout << "Paragem: "; //<< //nome da paragem;
			cout << "Autocarro: " << bus[x].matricula << " Motorista: " << bus[x].condutor << endl;
			int n_utilzadores;
			int n = 0;
			cout << "Passageiros: ";
			while(head) 
			{
				cout << head->utilizadores->dados.primeiro_nome<< " " <<temp->dados.n_bilhete <<  ", ";
				head = head->seguinte;
				temp = temp->seguinte;
			}
		}
}
