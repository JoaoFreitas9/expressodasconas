#ifndef ARVORE_H
#define ARVORE_H
using namespace std;

struct node {
	int numero;
	node* esquerda;
	node* direita;
};

node* novo_no(int valor);
node* inserir_no(node* raiz, int valor);
void imprimeArvore(node* raiz, int nivel);
node* pesquisar_no(node* raiz, int valor);
node* remover_no(node* raiz, node* no, node* antes);
#endif
