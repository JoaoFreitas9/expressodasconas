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
    getline(cin, paragem);
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (paragem == temp->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            resultado = paragem;
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
    cin.ignore();
    getline(cin, paragem);
    nodo_paragem* temp = paragens;
    while (temp != NULL)
    {
        if (paragem == temp->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            resultado = paragem;
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

nodo_paragem* remover_bilhete(nodo_paragem* nome_da_paragem) {
   
    string paragem;
    string resultado = "";
    int verifica;
    int bilhete;
    cout << "Qual é a paragem que deseja realizar a opção: ";
    cin.ignore();
    getline(cin,paragem);
    nodo_paragem* temp = nome_da_paragem;
   while (temp != NULL)
    {
        if (paragem == temp->nome_da_paragem) {
            cout << "***Paragem encontrada***" << endl;
            cout << "Introduza o número do bilhete que deseja retirar: ";
            cin >> bilhete;
            resultado = paragem;
            temp->raiz = pesquisar_no(temp->raiz, bilhete);
            break;
        }
        temp = temp->seguinte;
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
    string resultado="";
    cout << "Introduza a matrícula do autocarro que deseja alterar o motorista: ";
    cin >> matricula;
    while (temp != NULL) {
        if (matricula == temp->dados.matricula) {
            cout << "***Autocarro com matricula associada encontrado***" << endl;
            cout << "Qual o novo motorista que deseja introduzir: ";
            cin.ignore();
            getline(cin,nome_motorista);
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
    nodo_passageiro* temp1 = lista_de_espera;
    int bilhete;
    cout << "Indique o número do bilhete do passageiro a remover: ";
    cin >> bilhete;
    int i = 0;
    int y=0;
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
            removeinicio(lista_de_espera);
        }
        else if (i == x) {
            removefim(lista_de_espera);
        }
        else {
            removeposicao(lista_de_espera, y);
        }
    }
    else {
        cout << "***O bilhete introduzido não existe***"<< endl;
    }
}

/*void remover_passageiro(nodo_autocarros* bus) {
    nodo_autocarros* temp = bus;
    nodo_autocarros* temp1 = bus;
    
    int bilhete;
    string matricula;
    string resultado = "";
    cout << "Introduza a matrícula do autocarro que deseja alterar o motorista: ";
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
        cout << "Indique o número do bilhete do passageiro a remover: ";
        cin >> bilhete;
        int i = 0;
        int y = 0;
        while (temp->dados.utilizadores != NULL) {
            if (temp->dados.utilizadores->dados.n_bilhete != bilhete) {
                i = i + 1;
                temp->dados.utilizadores = temp->dados.utilizadores->seguinte;
            }
            else {
                y = i;
                break;
            }
        }
        int x = 0;
        while (temp->dados.utilizadores != NULL) {
            x = x + 1;
            temp->dados.utilizadores = temp->dados.utilizadores->seguinte;
        }
        if (y == i) {

            if (i == 0) {
                removeinicio(lista_de_espera);
            }
            else if (i == x) {
                removefim(lista_de_espera);
            }
            else {
                removeposicao(lista_de_espera, y);
            }
        }
  
    }
    else {
        cout << "***Autocarro com matricula associada não encontrado***" << endl;
    }
    
}*/
