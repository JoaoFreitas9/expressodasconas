using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"passageiro.h"
#include"paragens.h"

void bilhete_crescente(nodo_paragem* paragens) {
    string paragem;
    string resultado = "";
    cout << "Qual é a paragem que deseja realizar a opção: ";
    cin >> paragem;
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (paragem == temp->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            resultado = temp->nome_da_paragem;
        }
        temp = temp->seguinte;
    }
    if (resultado == "") {
        cout << "***Paragem não encontrada***" << endl;
    }
    else {
        nodo_paragem* temp2 = paragens;
        while (temp2->nome_da_paragem != paragem) {
            temp2 = temp2->seguinte;
        }
        cout << "***Bilhetes por ordem crescente***" << endl;
        infixa(temp2->raiz);
    }

}

void bilhete_por_arvore_binaria(nodo_autocarros* bus, nodo_paragem* paragens) {
    string paragem;
    string resultado = "";
    cout << "Qual é a paragem que deseja realizar a opção: ";
    cin >> paragem;
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (paragem == temp->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            resultado = temp->nome_da_paragem;
        }
        temp = temp->seguinte;
    }
    if (resultado == "") {
        cout << "***Paragem não encontrada***" << endl;
    }
    else {

        nodo_paragem* temp2 = paragens;
        while (temp2->nome_da_paragem != paragem) {
            temp2 = temp2->seguinte;
        }
        int nivel = altura(temp2->raiz);
        cout << "***Bilhetes por ordem crescente***" << endl;
        imprimeArvore(temp2->raiz, nivel);
    }
}

node* remover_bilhete(node* raiz, nodo_paragem* nome_da_paragem) {
    node* no = raiz;
    node* prev = NULL;
    string paragem;
    string resultado = "";
    int bilhete;
    cout << "Qual é a paragem que deseja realizar a opção: ";
    cin >> paragem;
    nodo_paragem* temp = nome_da_paragem;
    while (temp != NULL)
    {
        if (paragem == temp->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            cout << "Introduza o número do bilhete que deseja retirar: ";
            cin >> bilhete;
            resultado = temp->nome_da_paragem;
            raiz = temp->raiz;
            remover_no(raiz, no, prev);
        }
        else if (no->numero > bilhete) {
            prev = no;
            no = no->esquerda;
        }
        else {
            prev = no;
            no = no->direita;
        }

    }
    return raiz;
}

nodo_autocarros* alterar_motorista(nodo_autocarros* bus) {
    nodo_autocarros* temp = bus;
    string matricula;
    string nome_motorista;
    string resultado="";
    cout << "Introduza a matrícula do autocarro que deseja alterar o motorista: ";
    cin >> matricula;
    while (temp != NULL) {
        if (matricula == temp->dados.matricula) {
            cout << "***Autocarro com matricula associada encontrado***" << endl;
            cout << "Qual o novo motorista que deseja introduzir: ";
            cin >> nome_motorista;
            temp->dados.condutor = nome_motorista;
            resultado = nome_motorista;
            temp = temp->seguinte;
        }
        else {
            temp = temp->seguinte;
        }
    }
    if (resultado == "") {
        cout << "***Autocarro com matricula associada não encontrado***" << endl;
    }
    return bus;
}

void remover_fila_espera(nodo_passageiro* lista_de_espera) {
    nodo_passageiro* temp = lista_de_espera;
    int bilhete;
    cout << "Indique o número do bilhete do passageiro a remover: ";
    cin >> bilhete;
    while (temp->dados.n_bilhete != NULL) {
        if (bilhete != temp->dados.n_bilhete) {
            temp = temp->seguinte;
        }
        else {
            delete temp;
            temp = temp->seguinte;
        }
    }
}

void remover_passageiro(nodo_autocarros* bus) {
    nodo_autocarros* temp = bus;
    int bilhete;
    cout << "Indique o número do bilhete do passageiro a remover: ";
    cin >> bilhete;
    while (temp->dados.utilizadores->dados.n_bilhete != NULL) {
        if (bilhete != temp->dados.utilizadores->dados.n_bilhete) {
            temp = temp->seguinte;
        }
        else {
            delete temp;
            temp = temp->seguinte;
        }
    }
}
