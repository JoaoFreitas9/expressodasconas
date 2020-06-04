using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"passageiro.h"

void bilhete_crescente(nodo_autocarros*bus, nodo_paragem* paragens) {
    string paragem;
    string resultado = "";
    cout << "Qual é a paragem que deseja realizar a opção: ";
    cin >> paragem;
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (paragem==temp->nome_da_paragem) {
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
