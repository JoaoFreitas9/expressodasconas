using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"passageiro.h"
#include"paragens.h"

void bilhete_crescente(nodo_paragem* paragens, nodo_paragem*temp1) {
    string resultado = "";
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (temp1->nome_da_paragem == temp->nome_da_paragem) {
            cout << "***Bilhetes por ordem crescente***" << endl;
            cout << temp->nome_da_paragem << ":" << endl;
            resultado = "encontrado";
        }
        temp = temp->seguinte;
    }
    if (resultado == "") {
        cout << "***Paragem não encontrada***" << endl;
    }
    else {
        nodo_paragem* temp2 = paragens;
        while (temp2->nome_da_paragem != temp1->nome_da_paragem) {
            temp2 = temp2->seguinte;
        }
        
        infixa(temp2->raiz);
    }

}

void bilhete_por_arvore_binaria(nodo_autocarros* bus, nodo_paragem* paragens, nodo_paragem*temp1) {
    string paragem;
    string resultado = "";
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (temp1->nome_da_paragem == temp->nome_da_paragem) {
            resultado = "encontrado";
        }
        temp = temp->seguinte;
    }
    if (resultado == "") {
        cout << "***Paragem não encontrada***" << endl;
    }
    else {

        nodo_paragem* temp2 = paragens;
        while (temp2->nome_da_paragem != temp1->nome_da_paragem) {
            temp2 = temp2->seguinte;
        }
        int nivel = altura(temp2->raiz);
        cout << temp1->nome_da_paragem << ":" << endl;
        imprimeArvore(temp2->raiz, nivel);
    }
}

nodo_paragem* remover_bilhete(nodo_paragem* nome_da_paragem, nodo_paragem * temp,nodo_autocarros*bus) 
{
    string resultado = "";
    int bilhete;
    nodo_paragem* temp1 = nome_da_paragem;
    while (temp != NULL)
    {
        if (temp->nome_da_paragem == temp1->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            cout << "Introduza o número do bilhete que deseja retirar: ";
            cin >> bilhete;
            resultado = "encontrado";
            temp1->raiz = pesquisar_no(temp1->raiz, bilhete);
            break;
        }
        temp1 = temp1->seguinte;
    }
    if (resultado == "") {
        cout << "***Paragem não encontrada***" << endl;
    }
    return nome_da_paragem;
}

nodo_autocarros* alterar_motorista(nodo_autocarros* bus) {
    nodo_autocarros* temp = bus;
    string matricula;
    string nome_motorista;
    string resultado = "";
    cout << "Introduza a matrícula do autocarro que deseja alterar o motorista: ";
    cin >> matricula;
    while (temp != NULL) {
        if (matricula == temp->dados.matricula) {
            cout << "***Autocarro com matricula associada encontrado***" << endl;
            cout << "Qual o novo motorista que deseja introduzir: ";
            cin.ignore();
            getline(cin, nome_motorista);
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

nodo_passageiro* remover_fila_espera(nodo_passageiro* lista_de_espera) {
    nodo_passageiro* temp = lista_de_espera;
    nodo_passageiro* temp1 = lista_de_espera;
    int bilhete;
    cout << "Indique o número do bilhete do passageiro a remover: ";
    cin >> bilhete;
    int i = 0;
    int y = -1;
    while (temp != NULL) {
        if (temp->dados.n_bilhete != bilhete) {
            i = i + 1;
            temp = temp->seguinte;
        }
        else {
            y = i;
            break;
        }
    }
    int x = 0;
    while (temp1 != NULL) {
        x = x + 1;
        temp1 = temp1->seguinte;
    }
    if (y == i) {

        if (i == 0) {
            lista_de_espera = removeinicio(lista_de_espera);
        }
        else if (y == x) {
            lista_de_espera = removefim(lista_de_espera);
        }
        else {
            lista_de_espera = removeposicao(lista_de_espera, y);
        }
    }
    else {
        cout << "***O bilhete introduzido não existe***" << endl;
    }
    return lista_de_espera;
}

nodo_autocarros* remover_passageiro(nodo_autocarros* bus) {
    nodo_autocarros* temp = bus;
    nodo_autocarros* temp1 = bus;
    nodo_autocarros* temp2 = bus;
    
    int bilhete;
    string matricula;
    string resultado = "";
    cout << "Introduza a matrícula do autocarro pretendido: ";
    cin >> matricula;
    while (temp != NULL) {
        if (matricula == temp->dados.matricula) {
            cout << "***Autocarro com matricula associada encontrado***" << endl;
            resultado = matricula;
            break;
        }
        else {
            temp = temp->seguinte;
        }
    }
    if (resultado != "") {
        temp->dados.utilizadores = remover_fila_espera(temp->dados.utilizadores);
    }
    else {
        cout << "***Autocarro com matricula associada não encontrado***" << endl;
    }
    return bus;
}
