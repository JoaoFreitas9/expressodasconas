#include<iostream>
#include<string>
#include"passageiro.h"
#include<iomanip>
using namespace std;

nodo_autocarros* criaNo_autocarro(autocarro valor) {
    nodo_autocarros* novo = new nodo_autocarros;
    novo->dados = valor;
    novo->seguinte = NULL;
    return novo;
}

nodo_autocarros* insereInicio_autocarro(nodo_autocarros* inicio, autocarro valor) {
    nodo_autocarros* novo = criaNo_autocarro(valor);
    novo->seguinte = inicio;
    inicio = novo;
    return inicio;
}

nodo_autocarros* iteracao_autocarro(nodo_autocarros* paragens, autocarro valor, int n_paragens) {
    int i = 0;
    nodo_autocarros* temp = paragens;
    while (temp != NULL) {
        i = i + 1;
        temp = temp->seguinte;
    }
    if (i < n_paragens) {
        paragens = insereInicio_autocarro(paragens, valor);
    }
    else {
        paragens = insereInicio_autocarro(paragens, valor);
        paragens = removefim_autocarro(paragens);
    }
    return paragens;
}


nodo_autocarros* removefim_autocarro(nodo_autocarros* head) {
    nodo_autocarros* temp = head;
    while (temp->seguinte->seguinte != NULL) {
        temp = temp->seguinte;
    }
    delete temp->seguinte;
    temp->seguinte = NULL;
    return head;
}

void visualizacao(nodo_passageiro* espera)
{
    cout << "Fila de Espera:" << endl;
    int a = 0;
    nodo_passageiro* temp = espera;
    cout << left << setw(30);
    while (temp != NULL) {
        a = a + 1;
        cout << temp->dados.ultimo_nome << left << setw(30);
        if (a == 3) {
            cout << endl;
            a = 0;
        }
        temp = temp->seguinte;
    }
    cout << endl;
}

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



nodo_passageiro* gera_lista_de_espera(string* primeiro_nomes, string* ultimo_nomes, int* n_bilhetes) {
    nodo_passageiro* resultado = NULL;
    int i = 0;
    while (i < 30) {
        passageiro valor;
        int y = rand() % 43;
        int x = rand() % 96;
        valor.primeiro_nome = primeiro_nomes[y];
        valor.ultimo_nome = ultimo_nomes[x];
        int n = rand() % 9999;
        while (n_bilhetes[n] == -1) {
            n = rand() % 9999;
        }
        valor.n_bilhete = n_bilhetes[n];
        n_bilhetes[n] = -1;
        resultado = insereInicio(resultado, valor);
        i = i + 1;
    }
    return resultado;
}


nodo_passageiro* adiciona_quinze(string* primeiro_nomes, string* ultimo_nomes, int* n_bilhetes, nodo_passageiro* lista_de_espera) {
    nodo_passageiro* resultado = NULL;
    int i = 0;
    while (i < 15) {
        passageiro valor;
        int y = rand() % 43;
        int x = rand() % 96;
        valor.primeiro_nome = primeiro_nomes[y];
        valor.ultimo_nome = ultimo_nomes[x];
        int n = rand() % 9999;
        while (n_bilhetes[n] == -1) {
            n = rand() % 9999;
        }
        valor.n_bilhete = n_bilhetes[n];
        n_bilhetes[n] = -1;
        resultado = insereInicio(resultado, valor);
        i = i + 1;
    }
    nodo_passageiro* temp = resultado;
    while (temp != NULL) {
        temp = temp->seguinte;
    }
    temp = lista_de_espera;
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

autocarro gera_autocarro(string* primeiro_nome, string* ultimo_nome, nodo_passageiro* lista_de_espera, int& n_passageiros_lista_espera, char* caracteres) {
    autocarro resultado;
    resultado.matricula = gera_matricula(caracteres);
    int y = rand() % 43;
    int z = rand() % 96;
    string nome = primeiro_nome[y] + " " + ultimo_nome[z];
    resultado.condutor = nome;
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
    int j = 0;
    while (j < x) {
        lista_de_espera = removefim(lista_de_espera);
        j = j + 1;
    }
    return resultado;
}

nodo_autocarros* altera_motorista(autocarro) {
    string amatricula;
    string ocondutor;
    cout << "Introduza a matrícula do autocarro: " << endl;
    cin >> amatricula;
    if (amatricula == autocarro.matricula) {
        cout << "***Matrícula Encontrada***" << endl;
        cout << endl;
        cout << "Introduza o novo nome para o motorista: " << endl;
        cin >> ocondutor;
    }
    else {
        cout << "***ERRO: Matrícula não encontrada, por favor tente outra vez."
            altera_motorista(autocarro);
    }
}
