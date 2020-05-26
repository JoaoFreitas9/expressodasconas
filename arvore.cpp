#include <iostream>
#include "arvore.h"
#include <string>
#include <iomanip>
using namespace std;

node* novo_no(int valor)
{
	node* novo = new node;
	novo->numero = valor;
	novo->esquerda = NULL;
	novo->direita = NULL;
	return novo;
}

node* inserir_no(node* raiz, int valor) 
{
	if (raiz == NULL) {
		return novo_no(valor);
	}
	else if (valor < raiz->numero) {
		raiz->esquerda = inserir_no(raiz->esquerda, valor);
	}
	else {
		raiz->direita = inserir_no(raiz->direita, valor);
	}
	return raiz;
}

void imprimeArvore(node* raiz, int nivel) {

	if (raiz == NULL) {
		cout << endl;
		return;
	}
	imprimeArvore(raiz->direita, nivel + 1);

	for (int i = 0; i < nivel; i++)
		cout << "\t";

	cout << raiz->numero << endl;

	imprimeArvore(raiz->esquerda, nivel + 1);

}

node* pesquisar_no(node* raiz, int valor) 
{
	node* no = raiz;
	node* antes = NULL;
	while (no != NULL) {
		if (no->numero == valor) {
			cout << "***Número de bilhete encontrado***";
		}
		else if (no->numero > valor) {
			antes = no;
			no = no->esquerda;
		}
		else {
			antes = no;
			no = no->direita;
		}
	}
	return raiz;
}

node* remover_no(node* raiz, node* no, node* antes) 
{
	if (antes == NULL) {
		if (no->esquerda == NULL && no->direita == NULL) {
			raiz == NULL;
		}
		else if (no->esquerda != NULL && no->direita == NULL) {
			raiz = no->esquerda;
		}
		else if (no->esquerda == NULL && no->direita != NULL) {
			raiz = no->direita;
		}
		else {
			node* temp = no->esquerda;
			while (temp->direita == NULL) {
				antes = temp;
				temp = temp->direita;
			}
		}
		swap(temp->numero, no->numero);
		if (antes->numero > no->numero || antes == raiz) {
			antes->esquerda = temp->esquerda;
		}
		else {
			antes->direita = temp->esquerda;
		}
	}
	else {
		if (no->esquerda == NULL && no->direita == NULL) {
			if (antes->numero > no->numero) {
				antes->esquerda = NULL;
			}
			else {
				antes->direita == NULL;
			}
		}
		else if (no->esquerda == NULL && no->direita != NULL) {
			if (antes->numero > no->numero) {
				antes->esquerda = no->direita;
			}
			else {
				antes->direita = no->direita;
			}
		}
		else if (no->esquerda != NULL && no->direita == NULL) {
			if (antes->numero > no->numero) {
				antes->esquerda = no->numero;
			}
			else {
				antes->direita = no->direita;
			}
		}
		else {
			node* temp = no->esquerda;
			antes = no;
			while (temp->direita != NULL) {
				antes = temp;
				temp = temp->direita;
			}
		}
		swap(temp->numero, no->numero);
		if (antes->numero > no->numero || no == antes) {
			antes->esquerda = no->esquerda;
		}
		else {
			antes->direita = no->esquerda;
		}
	}
}
