#include<iostream>
#include"autocarro.h"
#include<string>
#include"passageiro.h"

nodo_autocarros* criaNo(autocarro valor) {
	nodo_autocarros* novo = new nodo_autocarros;
	novo->dados = valor;
	novo->seguinte = NULL;
	return novo;
}

nodo_autocarros* iteração(nodo_autocarros* paragens, autocarro valor) {
	int i = 0;
	int n_paragens = 9;
	for (i = 0; i < n_paragens;i++){
		nodo_autocarros* novo = new nodo_autocarros[i];
		if (i == 9){
			nodo_autocarros* removeultimo(nodo_autocarros);
			nodo_autocarros* insereInicio(nodo_autocarros);
		}

}

nodo_autocarros* insereInicio(nodo_autocarros * inicio, autocarro valor){
	nodo_autocarros* novo = criaNo(valor);
	novo->seguinte = inicio;
	inicio = novo;
	return inicio;
}

nodo_autocarros * removeultimo(nodo_autocarros * ultimo , autocarro valor) {
	nodo_autocarros* novo = criaNo(valor);
	while (novo->seguinte != NULL) {
		ultimo = novo->seguinte;
		delete[ultimo];
		ultimo->seguinte = NULL;
	}
}