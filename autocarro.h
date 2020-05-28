#include"passageiro.h"


struct nodo_autocarros {
	autocarro dados;
	nodo_autocarros* seguinte;
};

nodo_autocarros* insereInicio(nodo_autocarros* inicio, autocarro valor);
nodo_autocarros* iteração(nodo_autocarros* paragens, autocarro valor);
nodo_autocarros* criaNo(autocarro valor);
nodo_autocarros* removeultimo(nodo_autocarros* ultimo, autocarro valor);