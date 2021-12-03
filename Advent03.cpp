#include "Advent03.h"

#include<iostream>
#include<bitset>
#include<vector>


using std::ifstream;
using std::string;
using std::bitset;
using std::vector;
using std::cout;

void analizarBits(ifstream& in, string archivo) {

	//cambiar el tamaño del bitset si es diferente
	vector<bitset<12>> datos;
	bitset<12> gamma;
	bitset<12> epsil;

	in.open(archivo);
	if (in.good()) {
		string line = "";
		while(!in.eof()) {
			std::getline(in, line);
			datos.push_back(bitset<12>(line));
		}

		for(unsigned i = 0; i < 12/*tamaño de cada bitset*/; ++i) {
			int nUnos = 0;
			for (auto& bs : datos) {
				if (bs[i]) {
					//si es uno
					++nUnos;
				}
				else {
					--nUnos;
				}
			}

			if (nUnos > datos.size() / 2) gamma[i] = 1; //si el numero de unos es mayor que la mitad de datos
			else gamma[i] = 0;

		}
		//epsilon es not gamma
		epsil = ~gamma;

		auto vGamma = gamma.to_ulong();
		auto vEpsil = epsil.to_ulong();

		cout << "Gamma * epsilon = " << vGamma * vEpsil << std::endl;
	}

}

unsigned bitMasFrecuente(std::vector<std::bitset<12>>& datos, unsigned pos, unsigned bit /*1 o 0*/)
{
	unsigned nbit = 0;
	for (auto& bs : datos) {
		if (bs[pos] == bit) ++nbit;
	}

	if (nbit >= datos.size() / 2) return bit;
	if (bit == 1) return 0;
	else return 1;
	
}

unsigned long oxigen(std::ifstream& in, std::string archivo) {
	in.open(archivo);
	vector<bitset<12>> datos;

	if (in.good()) {
		string line = "";

		while (!in.eof()) {
			std::getline(in, line);
			datos.push_back(bitset<12>(line));
		}

		for (unsigned i = 11; i >= 0 && datos.size() != 1; --i) {
			vector<bitset<12>> aux;
			unsigned bitFrecuen = 0, nUnos = 0, nCeros = 0;

			//buscamos el bit más frecuente
			for (auto& bs : datos) {
				if (bs[i]) ++nUnos;
				else ++nCeros;
			}

			if (nUnos >= nCeros) bitFrecuen = 1;
			else bitFrecuen = 0;

			//cout << "bitFrecue: " << bitFrecuen << std::endl;

			for (auto& bs : datos) {
				if (bs[i] == bitFrecuen) {
					//cout << bs << std::endl;
					aux.push_back(bs);
				}
			}
			//cout << std::endl;
			datos = aux;
		}
	}
	//cout << datos[0] << std::endl;
	in.close();
	return datos[0].to_ulong();
}

unsigned long co2(std::ifstream& in, std::string archivo) {
	in.open(archivo);
	vector<bitset<12>> datos;

	if (in.good()) {
		string line = "";

		while (!in.eof()) {
			std::getline(in, line);

			datos.push_back(bitset<12>(line));
		}

		//la i se debe variar segun el tamaño del bitset
		for (unsigned i = 11; i >= 0 && datos.size() != 1; --i) {
			vector<bitset<12>> aux;
			unsigned bitFrecuen = 0, nUnos = 0, nCeros = 0;

			//buscamos el bit más frecuente
			for (auto& bs : datos) {
				if (bs[i]) ++nUnos;
				else ++nCeros;
			}

			//quedamos con el bit menos frecuente
			if (nCeros <= nUnos) bitFrecuen = 0;
			else bitFrecuen = 1;

			//cout << "bitFrecue: " << bitFrecuen << std::endl;

			for (auto& bs : datos) {
				if (bs[i] == bitFrecuen) {
					//cout << bs << std::endl;
					aux.push_back(bs);
				}
			}
			//cout << std::endl;
			datos = aux;
		}
	}
	//cout << datos[0] << std::endl;
	in.close();
	return datos[0].to_ulong();
}
