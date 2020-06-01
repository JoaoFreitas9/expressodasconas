#ifndef PARAGENS_H
#define PARAGENS_H
#include <iostream>
#include <string>
using namespace std;

struct node {
	int numero;
	node* esquerda;
	node* direita;
};

struct nodo_paragem {
	nodo_paragem* seguinte;
	node* raiz;
	string nome_da_paragem;
};

nodo_paragem* insereInicio_paragem(nodo_paragem* inicio, nodo_paragem* novo);
nodo_paragem* gera_paragens(string* paragens_nomes, int n_paragens);
node* novo_no(int valor);
node* inserir_no(node* raiz, int valor);
void imprimeArvore(node* raiz, int nivel);
node* pesquisar_no(node* raiz, int valor);
node* remover_no(node* raiz, node* no, node* antes);
void insere_valor_posicao_paragem(nodo_paragem* lista_de_paragens, int posicao, int valor_n_bilhete);
#endif
