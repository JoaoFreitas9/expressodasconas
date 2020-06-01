using namespace std;
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <time.h>
#include"escritaeleitura.h"
#include"passageiro.h"
#include"paragens.h"
#include"interacaopp.h"

int main(){
	srand(time(NULL));
	locale::global(locale(""));
	string* primeiro_nomes = leprimeironome("primeiro_nome.txt");
	string* ultimo_nomes = leultimonome("ultimo_nome.txt");
	string* paragens_nomes = leparagens("paragens.txt");
	int* n_bilhetes = gera_lista_bilhetes();
	int n_paragens= rand() % 5 + 6;
	char matricula[36] = {'0','1','2','3','4','5','6','7','8','9', 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	nodo_passageiro* lista_de_espera = NULL;
	int n_passageiros_lista_espera = 30;
	lista_de_espera = gera_lista_de_espera(primeiro_nomes, ultimo_nomes, n_bilhetes);
	visualizacao(lista_de_espera);
	nodo_paragem* lista_de_paragens = NULL;
	lista_de_paragens = gera_paragens(paragens_nomes, n_paragens);
	nodo_autocarros* lista_de_autocarros = NULL;
	autocarro primeiro_autocarro = gera_autocarro(primeiro_nomes, ultimo_nomes, lista_de_espera, n_passageiros_lista_espera, matricula);
	lista_de_autocarros = insereInicio_autocarro(lista_de_autocarros, primeiro_autocarro);
	char opcao;
	bool sair = false;
	while (!sair) {
		bool voltar = false;
		cout << "Escolha a sua opção:" << endl;
		cout << "(s)eguinte ou (o)pções:  ";
		std::cin >> opcao;
		switch (opcao)
		{
		case 's':
            primeiro_autocarro = gera_autocarro(primeiro_nomes, ultimo_nomes, lista_de_espera, n_passageiros_lista_espera, matricula);
			lista_de_autocarros = iteracao_autocarro(lista_de_autocarros, primeiro_autocarro, n_paragens);
			lista_de_espera=adiciona_quinze(primeiro_nomes,ultimo_nomes,n_bilhetes,lista_de_espera);
			interacaoprograma(lista_de_autocarros,lista_de_paragens);
			break;
		case 'o':
			char selecao;
			while (!voltar)
			{
				cout << "\nEscolha uma opcao:\n";
				cout << "1. Remover passageiros nos autocarros" << endl;
				cout << "2. Remover passageiros em fila de espera" << endl;
				cout << "3. Apresentar bilhetes por paragem" << endl;
				cout << "4. Alterar motorista" << endl;
				cout << "5. Remover bilhete da paragem" << endl;
				cout << "0. Voltar" << endl;
				std::cin >> selecao;
				switch (selecao)
				{
				case '1':
					cout << "***Escolheu a opção Remover passageiros nos autocarros***" << endl;
					break;
				case'2':
					cout << "***Escolheu a opção Remover Passageiros em Fila de Espera***" << endl;
					break;
				case '3':
					cout << "***Escolheu a opção Apresentar Bilhetes por Paragem***" << endl;
					break;
				case'4':
					cout << "***Escolheu a opção Alterar Motorista***" << endl;
					break;
				case '5':
					cout << "***Escolheu a opção Remover Bilhete da Paragem***" << endl;
					break;
				case'0':
					cout << "***Escolheu a opção de voltar***" << endl;
					voltar = true;
					break;
				}
			}
			break;
		default:
			cout << "Inseriu um caratere inválido. Prima ENTER para voltar " << endl;
			break;
		}
	}
	std::cin.sync();
	std::cin.get();
	return 0;
}
