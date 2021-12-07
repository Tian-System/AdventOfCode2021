#include "Advent06.h"

#include<vector>
#include<regex>
#include<iostream>
#include<map>

using std::string;
using std::ifstream;
using std::regex;
using std::vector;
using std::sregex_iterator;
using std::map;

void crecimientoDeLF(std::ifstream& in, std::string archivo, int dias)
{
	in.open(archivo);
	vector<int> lanterFish;

	if (in.good()) {
		string pattern = "[[:digit:]]+";
		regex rg(pattern);
		string line = "";

		std::getline(in, line);
		for (sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
			lanterFish.push_back(std::stoi(it->str()));
		}
		
		for (int i = 0; i < dias; ++i) {
			unsigned size = lanterFish.size();

			for (unsigned j = 0; j < size; j++) {
				if (lanterFish[j] == 0) {
					lanterFish.push_back(8);
					lanterFish[j] = 7;
				}

				--lanterFish[j];

			}
		}
	}

	std::cout << "****************************" << std::endl;
	std::cout << "Answer: " << lanterFish.size();
	in.close();
}

void crecimientoDeLF2(std::ifstream& in, std::string archivo, int dias)
{
	in.open(archivo);
	map<int, unsigned long long> groupFish;
	unsigned long long ans = 0;

	if (in.good()) {
		string pattern = "[[:digit:]]+";
		regex rg(pattern);
		string line = "";

		std::getline(in, line);
		for (sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
			int timer = std::stoi(it->str());
			++groupFish[timer];
		} //agrupamos los peces por su temporizador

		for (int i = 0; i < dias; ++i) {
			map<int, unsigned long long> groupAux;


			for (unsigned j = 0; j <= 8; j++) {
				//si se trata del temporizador 0, groupAux[7] = groupFish[0]
				if (j == 0) {
					groupAux[6] = groupFish[j];
					groupAux[8] = groupFish[j];
				}
				else { //si es distinto a 0, 
					groupAux[j - 1] += groupFish[j];
				}
			}

			groupFish = groupAux;

		}

		for (unsigned i = 0; i <= 8; ++i) {
			ans += groupFish[i];
		}
		
	}

	std::cout << "****************************" << std::endl;
	std::cout << "Answer: " << ans << std::endl;
	in.close();

	
}
