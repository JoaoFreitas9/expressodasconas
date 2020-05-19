#include<iostream>
#include<string>
#include"passageiro.h"
using namespace std;

nodo_passageiro* criaNo(passageiro valor) {
    nodo_passageiro* novo = new nodo_passageiro;
    novo->dados = valor;
    novo->seguinte = NULL;
    return novo;
}


nodo_passageiro* insereInicio(nodo_passageiro* inicio, passageiro valor) {
    nodo_passageiro* novo = criaNo(valor);
    novo->seguinte = inicio;
    inicio = novo;
    return inicio;
}



nodo_passageiro* gera_lista_de_espera(string* primeiro_nomes, string* ultimo_nomes,int*n_bilhetes) {
    nodo_passageiro* resultado = new nodo_passageiro;
    int i = 0;
    passageiro valor;
    while (i < 30) {
        int y = rand() % 43;
        int x = rand() % 96;
        valor.primeiro_nome = primeiro_nomes[y];
        valor.ultimo_nome = ultimo_nomes[x];
        int n = rand() % 9999;
        while (n_bilhetes[n] == -1) {
            int n = rand() % 9999;
        }
        valor.n_bilhete = n_bilhetes[n];
        n_bilhetes[n] = -1;
        resultado=insereInicio(resultado, valor);
        i = i + 1;
    }
    return resultado;
}

int* gera_lista_bilhetes() {
    int* resultado = new int[10000];
    int j = 0;
    while (j < 10000) {
        resultado[j] = j;
        j = j + 1;
    }
    return resultado;
}
