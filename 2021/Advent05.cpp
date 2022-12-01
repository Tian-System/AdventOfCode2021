#include "Advent05.h"

#include<vector>
#include<iostream>
#include<list>
#include<regex>


using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::regex;

struct point {
	unsigned x;
	unsigned y;
};

void analizadorViento(std::ifstream& in, std::string archivo, unsigned row, unsigned col)
{	
	in.open(archivo);
	int ans = 0;

	if (in.good()) {
		vector<vector<int>> map(row);
		for (auto& fila : map) {
			fila.resize(col);
			
		} //creamos un vector de row x col

		
		list<vector<point>> fuentesHidro;
		string pattern = "[[:digit:]]+";
		regex r(pattern);

		string line = "";
		while (!in.eof()) {
			std::getline(in, line);

			
			point aux1, aux2;
			
			vector<int> nums;
			for (std::sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it) {
				nums.push_back(std::stoi(it->str()));
			}

			aux1.x = nums[0];
			aux1.y = nums[1];
			aux2.x = nums[2];
			aux2.y = nums[3];
			

			vector<point> fuente{ aux1, aux2 };
			fuentesHidro.push_back(fuente); 
		}

		for (auto& fuente : fuentesHidro) {
			point &ini = fuente[0];
			point &fin = fuente[1];
			if (ini.x == fin.x || ini.y == fin.y) {
				//tratamos solo los que tengan un componente igual
				cout << ini.x  << ", " << ini.y << " -> " << fin.x << ", " << fin.y << endl;
				//cout << "--------------------------" << endl;
				
				if (ini.x == fin.x && ini.y == fin.y) {
					++map[ini.x][ini.y];

				}
				
				else if (ini.x == fin.x) {
					//si las componentes x son iguales
					if (ini.y > fin.y) { //si el componente y inicial es mayor, intercambiar
						unsigned aux = ini.y;
						ini.y = fin.y;
						fin.y = aux;
					}
					for (unsigned i = ini.y; i <= fin.y; ++i) {
						++map[ini.x][i];
					}


				}

				else if (ini.y == fin.y) {
					if (ini.x > fin.x) {
						unsigned aux = ini.x;
						ini.x = fin.x;
						fin.x = aux;
					}
					for (unsigned i = ini.x; i <= fin.x; ++i) {
						++map[i][ini.y];
					}
				} 
				

			}

		}

		for (auto& fila : map) {
			for (auto& col : fila) {
				//cout << " " << col << " ";
				if (col >= 2) {
					
					++ans;
				}
			}
			//cout << endl;
		}
	}
	cout << "...................................." << endl;
	cout << "Answer: " << ans << endl;

}

void analizadorViento2(std::ifstream& in, std::string archivo, unsigned row, unsigned col)
{
	in.open(archivo);
	int ans = 0;

	if (in.good()) {
		vector<vector<int>> map(row);
		for (auto& fila : map) {
			fila.resize(col);

		} //creamos un vector de row x col


		list<vector<point>> fuentesHidro;
		string pattern = "[[:digit:]]+";
		regex r(pattern);

		string line = "";
		while (!in.eof()) {
			std::getline(in, line);


			point aux1, aux2;

			vector<int> nums;
			for (std::sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it) {
				nums.push_back(std::stoi(it->str()));
			}

			aux1.x = nums[0];
			aux1.y = nums[1];
			aux2.x = nums[2];
			aux2.y = nums[3];


			vector<point> fuente{ aux1, aux2 };
			fuentesHidro.push_back(fuente);
		}

		for (auto& fuente : fuentesHidro) {
			point ini = fuente[0];
			point fin = fuente[1];
			cout << ini.x << ", " << ini.y << " -> " << fin.x << ", " << fin.y << endl;
			if (ini.x == fin.x || ini.y == fin.y) {
				//tratamos solo los que tengan un componente igual
				cout << ini.x << ", " << ini.y << " -> " << fin.x << ", " << fin.y << endl;
				//cout << "--------------------------" << endl;

				if (ini.x == fin.x && ini.y == fin.y) {
					++map[ini.x][ini.y];

				}

				else if (ini.x == fin.x) {
					//si las componentes x son iguales
					if (ini.y > fin.y) { //si el componente y inicial es mayor, intercambiar
						unsigned aux = ini.y;
						ini.y = fin.y;
						fin.y = aux;
					}
					for (unsigned i = ini.y; i <= fin.y; ++i) {
						++map[ini.x][i];
					}


				}

				else if (ini.y == fin.y) {
					if (ini.x > fin.x) {
						unsigned aux = ini.x;
						ini.x = fin.x;
						fin.x = aux;
					}
					for (unsigned i = ini.x; i <= fin.x; ++i) {
						++map[i][ini.y];
					}
				}


			}
			else {
				while (!(ini.x == fin.x && ini.y == fin.y)) {
					++map[ini.x][ini.y];
					if (ini.x > fin.x) --ini.x;
					else if (ini.x < fin.x) ++ini.x;

					if (ini.y > fin.y) --ini.y;
					else if (ini.y < fin.y) ++ini.y;
				}
				++map[ini.x][ini.y];
			}

		}

		for (auto& fila : map) {
			for (auto& col : fila) {
				//cout << " " << col << " ";
				if (col >= 2) {

					++ans;
				}
			}
			//cout << endl;
		}
	}
	cout << "...................................." << endl;
	cout << "Answer: " << ans << endl;
}
