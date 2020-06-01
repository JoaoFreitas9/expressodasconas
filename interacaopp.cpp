#include <iostream>
#include "paragens.h"
#include"passageiro.h"
#include"interacaopp.h"
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void interacaoprograma(nodo_autocarros* lista_de_autocarros, nodo_paragem* lista_de_paragens) {
	nodo_autocarros* temp_autocarros = lista_de_autocarros;
	int posicao = 0;
	while (temp_autocarros != NULL) {
		nodo_passageiro* temp_passageiros = temp_autocarros->dados.utilizadores;
		nodo_passageiro* novo = NULL;
		while (temp_passageiros != NULL) {
			int x = rand() % 3;
			if (x == 1) {
				insere_valor_posicao_paragem(lista_de_paragens, posicao, temp_passageiros->dados.n_bilhete);
				temp_passageiros = temp_passageiros->seguinte;
			}
			else {
				novo = insereInicio(novo, temp_passageiros->dados);
				temp_passageiros = temp_passageiros->seguinte;
			}
		}
		temp_autocarros->dados.utilizadores = novo;
		posicao = posicao + 1;
		temp_autocarros = temp_autocarros->seguinte;
	}
}
