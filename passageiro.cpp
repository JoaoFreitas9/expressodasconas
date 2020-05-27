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
    resultado = criaNo(valor);
    while (i < 29) {
        y = rand() % 43;
        x = rand() % 96;
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

string gera_matricula(char* caracteres) {
    int i = 0;
    string matricula;
    while (i < 4) {
        int x = rand() & 35;
        matricula = matricula + caracteres[x];
        i = i + 1;
    }
    return  matricula;
}
nodo_passageiro* removefim(nodo_passageiro* head) {
    nodo_passageiro* temp = head;
    while (temp->seguinte->seguinte != NULL) {
        temp = temp->seguinte;
    }
    delete temp->seguinte;
    temp->seguinte = NULL;
    return head;
}

autocarro gera_autocarro(nodo_passageiro* lista_de_espera, int& n_passageiros_lista_espera,char* caracteres) {
    autocarro resultado;
    resultado.matricula = gera_matricula(caracteres);
    int x = rand() & 5 + 5;
    resultado.capacidade = x;
    resultado.quantidade = x;
    n_passageiros_lista_espera = n_passageiros_lista_espera - x;
    nodo_passageiro* temp = lista_de_espera;
    int i = 0;
    while (i < n_passageiros_lista_espera) {
        temp = temp->seguinte;
        i = i + 1;
    }
    resultado.utilizadores = temp;
    nodo_passageiro* temp2 = lista_de_espera;
    int j = 0;
    while (j < x) {
        lista_de_espera = removefim(lista_de_espera);
    }
    return resultado;
}

