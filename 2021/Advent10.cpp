#include<iostream>
#include "Advent10.h"
#include<list>;

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::list;


/*cada vez que leemos, se trata de abrir o cerrar, cuando se cierra, se comprueba si 
el anterior es justamente el s¨ªmbolo adecuado, si es el adecuado se elimina el anterior
si no lo es, paramos.
*/
void analizarSyntax(std::ifstream& in, std::string archivo)
{
	
	in.open(archivo);
	
	int ans = 0;

	if (in.good()) {
		string line = "";
		while (!in.eof()) {
			std::getline(in, line);
			string aux = "";
			for (const auto& c : line) {
				
				if (c == 40 || c == 60 || c == 91 || c == 123) {
					aux += c;
				}
				else {
					bool exit = false;
					
					switch (c)
					{
					case 41:
						if (aux[aux.size() - 1] != 40) {
							exit = true; 
							ans += CPARENTH;
						}
						break;
					case 62:
						if (aux[aux.size() - 1] != 60) {
							exit = true;
							ans += SIMMAYOR;
						}
						break;
					case 93:
						if (aux[aux.size() - 1] != 91) {
							exit = true;
							ans += CCORCHET;
						}
						break;
					case 125:
						if (aux[aux.size() - 1] != 123) {
							exit = true;
							ans += CLLAVES;
						}
						break;
						
					}

					if (exit) break;
					else aux.erase(aux.size() - 1, 1);
					

				}
			}
			cout << aux << endl;


		}

		cout << "***************************" << endl;
		cout << "Answer: " << ans << endl;

	}

	in.close();
	
}

void analizarSyntax2(std::ifstream& in, std::string archivo)
{

	in.open(archivo);

	list<long long> ans;

	if (in.good()) {
		string line = "";
		while (!in.eof()) {
			std::getline(in, line);
			string aux = "";
			bool isCorrupted = false;
			for (const auto& c : line) {

				if (c == 40 || c == 60 || c == 91 || c == 123) {
					aux += c;
				}
				else {
					bool exit = false;

					switch (c)
					{
					case 41:
						if (aux[aux.size() - 1] != 40) {
							exit = true;
							
						}
						break;
					case 62:
						if (aux[aux.size() - 1] != 60) {
							exit = true;
							
						}
						break;
					case 93:
						if (aux[aux.size() - 1] != 91) {
							exit = true;
							
						}
						break;
					case 125:
						if (aux[aux.size() - 1] != 123) {
							exit = true;
							
						}
						break;

					}

					if (exit) {
						isCorrupted = true;
						break;
					}
					else aux.erase(aux.size() - 1, 1);


				}
			}
			if (!isCorrupted) {
				cout << aux << endl;
				long long sumLine = 0;
				for (int i = aux.size(); i >= 0; --i) {
					char c = aux[i];
					switch (c)
					{
					case '(':
						sumLine = sumLine * 5 + IPARENTH;
						break;
					case '[':
						sumLine = sumLine * 5 + ICORCHET;
						break;
					case '{':
						sumLine = sumLine * 5 + ILLAVES;
						break;
					case '<':
						sumLine = sumLine * 5 + ISIMMAYOR;
						break;
					}
				}
				ans.push_back(sumLine);
			}


		}
		ans.sort();

		//buscar el elemento que esta en el medio
		int size = ans.size();
		for (int i = 0; i < size; ++i) {
			if (i == size/2) {
				cout << ans.front() << endl;
				break;
			}
			ans.pop_front();
		}

	}

	in.close();

}