#include "Advent01.h"
#include <string>
#include <vector>
#include <map>
#include <sstream>

using std::ifstream;
using std::string;
using std::vector;
using std::map;

int analizadorNumeros(ifstream& in, string archivo) {
	
	in.open(archivo, ifstream::in);
	int res = 0;

	if (in.good()) {
		string line = "";
		std::getline(in, line);
		int numero = std::stoi(line, nullptr,10); //leemos el primer numero

		//mientras no lleguemos al final del archivo
		while (!in.eof()) {
			std::getline(in, line);
			int aux = std::stoi(line);
			if (numero < aux) ++res;
			numero = aux;
		}
	}

	return res;

}

int analizadorNumeros2(std::ifstream& in , std::string archivo) {
	using std::istringstream;

	in.open(archivo, ifstream::in);
	int res = 0;
	vector<int> numeros;

	if(in.good()) {
		string line = "";
		int num = 0;

		//creamos la lista de n¨²meros
		while (!in.eof()) {
			std::getline(in, line);
			num = std::stoi(line, nullptr, 10);
			numeros.push_back(num);
		}

		num = numeros[0] + numeros[1] + numeros[2];
		for (unsigned i = 1; i < numeros.size() - 2; i++) {
			int aux = numeros[i] + numeros[i + 1] + numeros[i + 2];
			if (aux > num) res++;
			num = aux;
		}
	}

	return res;


}