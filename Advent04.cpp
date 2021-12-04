#include "Advent04.h"
#include <sstream>
#include <vector>
#include <list>
#include <regex>
#include <iostream>
#include <utility>

using std::list;
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;
using std::regex;
using std::cout;
using std::pair;


bool equal(vector<vector<pair<int, bool>>> lhs, vector<vector<pair<int, bool>>> rhs) {
	bool res = true;
	if (lhs.size() == rhs.size()) {
		for (unsigned i = 0; i < lhs.size() && res; ++i) {
			if (lhs[i].size() != rhs[i].size()) return false;
			for (unsigned j = 0; j < lhs.size() && res; ++j) {
				res = res && (lhs[i][j].first == rhs[i][j].first);
			}
		}
		return res;
	}
	return false;
}

void bingo(std::ifstream& in, std::string archivo)
{
	in.open(archivo);
	
	if (in.good()) {
		string pattern = "[[:digit:]]+";
		regex rg(pattern);
		string line = "";
		vector<int> randNums;
		list<vector<vector<pair<int, bool>>>> boards;


		int ans = 0;
		//leer los numeros del bingo
		std::getline(in, line);
		
		for (std::sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
			randNums.push_back(std::stoi(it->str())); //conseguimos la lista de numeros
		}
		
		std::getline(in, line); //saltar la linea vacia
		
		//conseguir las tablas
		while (!in.eof()) {

			
			vector<vector<pair<int, bool>>> tabla;
			for (unsigned i = 0; i < 5; ++i) {
				std::getline(in, line);
				vector<pair<int, bool>> fila;
				for (std::sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
					fila.push_back({ std::stoi(it->str()), false }); //conseguimos la lista de numeros
				}
				
				tabla.push_back(fila);
			}
			std::getline(in, line); //saltar la linea vacia

			boards.push_back(tabla);
		}

		for (const auto& num : randNums) {

			
			for (auto& board : boards) {
				//cada elemento cada tabla comprobar si es igual a num
				for (auto& fila : board) {

					for (auto& col : fila) {

						if (col.first == num) {
							col.second = true;
						}

					}
				}
			}

			//comprobar ahora si hay tabla ganadora

			vector<vector<pair<int, bool>>> *res = nullptr;
			for (auto& board : boards) {
				
				//buscar por fila
				bool romper = false;
				for (unsigned i = 0; i < board.size(); ++i) {
					bool encontrado = true;
					for (unsigned j = 0; j < board[i].size(); ++j) {
						encontrado = encontrado && board[i][j].second; //recorremos cada fila y comprobamos si encontrado sigue siendo true
					}

					if (encontrado) {
						romper = true;
						break;
					}
				}

				if (romper) {
					res = &board;
					break;
				}
				//buscar por columna
				for (unsigned i = 0; i < board.size(); ++i) {
					bool encontrado = true;
					for (unsigned j = 0; j < board.size(); ++j) {
						encontrado = encontrado && board[j][i].second;
					}

					if (encontrado) {
						romper = true;
						break;
					}
				}

				if (romper) {
					res = &board;
					break;
				}
				
			}

			//realizamos las menores modificaciones posibles
			if (res != nullptr) {
				ans = 0;
				for (auto& fila : *res) {
					for (auto& col : fila) {
						
						if (!col.second) {
							ans += col.first;
						}

					}

				}
				ans *= num;
				
				break;
				
			}


		}

		
		cout << ans << std::endl;
		

	}

	in.close();
}



void bingo2(std::ifstream& in, std::string archivo)
{
	in.open(archivo);

	if (in.good()) {
		string pattern = "[[:digit:]]+";
		regex rg(pattern);
		string line = "";
		vector<int> randNums;
		list<vector<vector<pair<int, bool>>>> boards;

		std::getline(in, line);

		for (std::sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
			randNums.push_back(std::stoi(it->str())); //conseguimos la lista de numeros
		}


		std::getline(in, line); //saltar la linea vacia

		//conseguir las tablas
		while (!in.eof()) {


			vector<vector<pair<int, bool>>> tabla;
			for (unsigned i = 0; i < 5; ++i) {
				std::getline(in, line);
				vector<pair<int, bool>> fila;
				for (std::sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
					fila.push_back({ std::stoi(it->str()), false }); //conseguimos la lista de numeros
				}

				tabla.push_back(fila);
			}
			std::getline(in, line); //saltar la linea vacia

			boards.push_back(tabla);
		}
		
		list<vector<vector<pair<int, bool>>>> winners;
		vector<int> numsAMult;

		for (auto& num : randNums) {
			for (auto& board : boards) {
				//cada elemento cada tabla comprobar si es igual a num
				for (auto& fila : board) {

					for (auto& col : fila) {

						if (col.first == num) {
							col.second = true;
						}

					}
				}
			}

			for (auto beg = boards.begin(); beg != boards.end(); ++beg) {
				bool found = false;
				for (unsigned row = 0; row < 5 && !found; ++row) {
					bool bingo = true;
					for (unsigned col = 0; col < 5; ++col) {
						bingo = bingo && (*beg)[row][col].second;
					}

					if (bingo) {
						found = true;
					}
				}

				for (unsigned col = 0; col < 5 && ! found; ++col) {
					bool bingo = true;
					for (unsigned row = 0; row < 5; ++row) {
						bingo = bingo && (*beg)[row][col].second;
					}
					if (bingo) {
						found = true;
					}

				}

				//cuando añadimos debemos comprobar si ya lo hemos añadido
				//no salimos del bucle porque puede que en un num hay dos tablas que den bingo
				if (found) {
					bool esta = false;
					for (auto& board : winners) {
						esta = esta || equal(board, *beg);
					}
					if (!esta) {
						winners.push_back(*beg);
						numsAMult.push_back(num);
					}
				}

			}
		}

		cout << winners.size() << std::endl;
		cout << numsAMult.size() << std::endl;
		cout << "***********************************" << std::endl;
		auto& lastWin = winners.back();
		auto& lastNum = numsAMult.back();

		int ans = 0;
		for (auto& fila : lastWin) {
			for (auto& col : fila) {
				if (!col.second) {
					ans += col.first;
				}
			}
		}
		ans *= lastNum;

		cout << ans << std::endl;

	}
	in.close();

}
