#ifndef opcoes_H
#define opcoes_H
using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"passageiro.h"
#include"paragens.h"

void bilhete_crescente(nodo_paragem* paragem);
void bilhete_por_arvore_binaria(nodo_autocarros* bus, nodo_paragem* paragens);
nodo_autocarros* alterar_motorista(nodo_autocarros* bus);
void remover_fila_espera(nodo_passageiro* lista_de_espera);
#endif
