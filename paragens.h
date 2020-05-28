#ifndef PARAGENS_H
#define PARAGENS_H
using namespace std;

struct paragem {
	string nome_da_paragem;
	node*arvore;
};

struct nodo_paragem {
	paragem dados;
	nodo_paragem* seguinte;
};

struct node {
	int numero;
	node* esquerda;
	node* direita;
};

nodo_paragem* criaNo_paragem(paragem valor);
nodo_paragem* insereInicio_paragem(nodo_paragem* inicio, paragem valor);
nodo_paragem* gera_paragens(string* paragens_nomes,int n_paragens);
node* novo_no(int valor);
node* inserir_no(node* raiz, int valor);
void imprimeArvore(node* raiz, int nivel);
node* pesquisar_no(node* raiz, int valor);
node* remover_no(node* raiz, node* no, node* antes);
#endif
