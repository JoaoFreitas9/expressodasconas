#include <iostream>
#include "paragens.h"
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;


nodo_paragem* insereInicio_paragem(nodo_paragem* inicio, nodo_paragem* novo) {
	novo->seguinte = inicio;
	inicio = novo;
	return inicio;
}

nodo_paragem* gera_paragens(string* paragens_nomes, int n_paragens) {
	nodo_paragem* resultado = NULL;
	int i = 0;
	while (i < n_paragens) {
		nodo_paragem* valor = new nodo_paragem;
		int x = rand() % 52;
		while (paragens_nomes[x] == " ") {
			x = rand() % 52;
		}
		valor->nome_da_paragem = paragens_nomes[x];
		valor->seguinte = NULL;
		valor->raiz = NULL;
		paragens_nomes[x] = " ";
		resultado = insereInicio_paragem(resultado, valor);
		i = i + 1;
	}
	return resultado;
}


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
	for (int i = 0; i < nivel; i++) {
		cout << "\t";
	}
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

node* remover_no(node* raiz, node* no, node* antes) {
	node* temp = NULL;
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
				antes->esquerda = no->direita;
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
	return raiz;
}

nodo_paragem* apresenta_bilhetes() {
	char opçao;
	cout << "Escolha uma das opções: \n\n1- Número do bilhete em ordem crescente.\n2- Número do bilhete em forma de árvore binária. " << endl;
	cin >> opçao;
	if (opçao == 1) {
		float precos[12];
		string produtos[12];
		int quantidade[12];
		for (int x = 0; x < n_slots; x++) {
			precos[x] = maquina[x].preco;
			produtos[x] = maquina[x].produto;			// Função do projeto da máquina de vendas para ordenar numeros crescentemente, falta por a funcionar
			quantidade[x] = maquina[x].quantidade;
		}
		for (int y = 0; y < n_slots; y++) {
			for (int z = 0; z < n_slots; z++) {
				if (precos[y] < precos[z]) {
					float aux = precos[y];
					string aux1 = produtos[y];
					int aux2 = quantidade[y];
					precos[y] = precos[z];
					precos[z] = aux;
					produtos[y] = produtos[z];
					produtos[z] = aux1;
					quantidade[y] = quantidade[z];
					quantidade[z] = aux2;
				}
			}
		}
		for (int x = 0; x < n_slots; x++) {
			cout << "Produto : " << produtos[x] << " | " << "Preço : " << precos[x] << " | " << "Quantidade: " << quantidade[x] << endl;
		}
		system("pause");
	}
	else if (opçao == 2) {
		imprimeArvore(raiz, nivel) {
		}
	else {
		cout << "Caratere inválido, por favor introduza um caratere válido." << endl;
		apresenta_bilhetes();
	}
}
	
