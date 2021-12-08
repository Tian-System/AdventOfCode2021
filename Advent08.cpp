#include "Advent08.h"
#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::regex;
using std::sregex_iterator;
using std::string;
using std::vector;

void analizadorSegmentos(std::ifstream& in, std::string archivo)
{
	in.open(archivo);
	int ans = 0;

	if (in.good()) {
		string patter = "[[:alpha:]]+";
		string line = "";
		regex rg(patter);
		while (!in.eof()) {
			std::getline(in, line);
			line.erase(0, line.find('|'));
			cout << line << endl;
			for (sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
				if ((it->str()).size() == 2 || (it->str()).size() == 4 || (it->str()).size() == 3 || (it->str()).size() == 7) {
					++ans;
				}

			}

		}

	}

	cout << "*******************************" << endl;
	cout << "Answer: " << ans << endl;

}

void analizadorSegmentos2(std::ifstream& in, std::string archivo)
{
	in.open(archivo);
	int ans = 0;
	vector<string> numeros;

	if (in.good()) {
		string patter = "[[:alpha:]]+";
		string line = "", firstPart = "", secondPart = "";

		regex rg(patter);
		while (!in.eof()) {
			std::getline(in, line);
			firstPart = line.substr(0, line.find('|'));
			secondPart = line.substr(line.find('|'));
			string nums[10];
			
			//separamos 
			for (sregex_iterator it(firstPart.begin(), firstPart.end(), rg), end_it; it != end_it; ++it) {
				switch ((it->str()).size())
				{
				case 2:
					nums[1] = it->str();
					break;
				case 3:
					nums[7] = it->str();
					break;
				case 4:
					nums[4] = it->str();
					break;
				case 8:
					nums[8] = it->str();
				default:
					break;
				}
			}

			for (sregex_iterator it(firstPart.begin(), firstPart.end(), rg), end_it; it != end_it; ++it) {
				string digit = it->str();
				int difChars = 0;
				//check first with 1
				for (const auto& c : digit) { //comprobamos con 1, cada vez que 1 no contenga un caracter, aumentar el numero de caracteres diferentes
					if (nums[1].find(c) == string::npos) {
						++difChars;
					}
				}
				if (difChars == 3) { //el numero de caracteres difernts es 3, se trata de un 3
					nums[3] = digit;
				}
				else {
					//check with 4 and 7
					difChars = 0; //sino comprobar con 4 y 7
					for (const auto& c : digit) { //si la letra no es comprendida ni en 4 ni 7, aunmentar numero de caracteres diferentes
						if (nums[4].find(c) == string::npos && nums[7].find(c) == string::npos) {
							++difChars;
						}

					}
					if (difChars == 1) { //si el numero de caracteres diferentes con 4 y 7 es 1, dependiendo del tamaño sera 5 o 9
						if (digit.size() == 5) nums[5] = digit;
						else if(digit.size() == 6) nums[9] = digit;
					}
					else if (difChars == 2) {
						if (digit.size() == 5) nums[2] = digit;
						else if (digit.size() == 6)
						{
							//volvemos a comprobar con 1
							difChars = 0;
							for (const auto& c : digit) {
								if (nums[1].find(c) == string::npos) {
									++difChars;
								}
							}
							if (difChars == 5) nums[6] = digit;
							else if (difChars == 4) nums[0] = digit;
						}

					}
					
				}
			}

			//tratar la segunda parte 
			string numero = "";
			for (sregex_iterator it(secondPart.begin(), secondPart.end(), rg), end_it; it != end_it; ++it) {
				string digito = it->str();
				bool isTwo = true, isThree = true;
				bool isZero = true, isSix = true;
				switch (digito.size())
				{
				case 2:
					numero += "1";
					break;
				case 3:
					numero += "7";
					break;
				case 4:
					numero += "4";
					break;
				case 7:
					numero += "8";
					break;
				case 5:

					
					
					for (const auto& c : digito) {
						isTwo = isTwo && (nums[2].find(c) != string::npos);
						isThree = isThree = isThree && (nums[3].find(c) != string::npos);
					}
					if (isTwo) {
						numero += "2";
					}
					else if (isThree) {
						numero += "3";
					}
					else {
						numero += "5";
					}
					break;
				case 6:
					
					
					for (const auto& c : digito) {
						isZero = isZero && (nums[0].find(c) != string::npos);
						isSix = isSix && (nums[6].find(c) != string::npos);
					}
					if (isZero) {
						numero += "0";
					} else if (isSix) {
						numero += "6";
					}
					else {
						numero += "9";
					}
					break;
					
				}

			}

			numeros.push_back(numero);


		}

		

		for (auto& num : numeros) {
			ans += std::stoi(num);
		}

	}

	cout << "*******************************" << endl;
	cout << "Answer: " << ans << endl;

}