#include<iostream>
#include<string>
#include<fstream>
#include"escritaeleitura.h"
using namespace std;

string* leprimeironome(string caminho) {
	ifstream file(caminho);
	string line = "";
	string* resultado = new string[44];
	int i = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			resultado[i] = line;
			i = i + 1;
		}
	}
	return resultado;
}
string* leultimonome(string caminho) {
	ifstream file(caminho);
	string line = "";
	string* resultado = new string[97];
	int i = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			resultado[i] = line;
			i = i + 1;
		}
	}
	return resultado;
}
string* leparagens(string caminho) {
	ifstream file(caminho);
	string line = "";
	string* resultado = new string[54];
	int i = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			resultado[i] = line;
			i = i + 1;
		}
	}
	return resultado;
}
