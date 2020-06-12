#ifndef opcoes_H
#define opcoes_H
using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"passageiro.h"
#include"paragens.h"

void bilhete_crescente(nodo_paragem* paragem, nodo_paragem*temp);
void bilhete_por_arvore_binaria(nodo_autocarros* bus, nodo_paragem* paragens,nodo_paragem*temp1);
nodo_autocarros* alterar_motorista(nodo_autocarros* bus);
nodo_passageiro* remover_fila_espera(nodo_passageiro* lista_de_espera);
nodo_autocarros*remover_passageiro(nodo_autocarros* bus);
nodo_paragem* remover_bilhete(nodo_paragem* nome_da_paragem, nodo_paragem* temp, nodo_autocarros*bus);
#endif
    
