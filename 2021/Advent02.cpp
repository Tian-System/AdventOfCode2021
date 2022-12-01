#include "Advent02.h"
#include <iostream>

using std::cout;
using std::ifstream;
using std::string;
void finalPosition(ifstream& in, string archivo) {
	in.open(archivo, ifstream::in);
	int horizontal = 0;
	int depth = 0;


	if (in.good()) {
		string line = "";
		while (!in.eof()) {

			std::getline(in, line);
			string direction = "";
			unsigned pos = line.find(' '); // buscar la posici車n del primer espacio en blanco
			direction = line.substr(0, pos);
			
			line.erase(0, pos + 1); //eliminamos posici車n de la linea leida
			
			int desplaz = std::stoi(line, nullptr, 10);
			if (direction == "forward") horizontal += desplaz;
			else if (direction == "down") depth += desplaz;
			else depth -= desplaz;
			
		}
	}

	cout << "Horizontal: " << horizontal << std::endl;
	cout << "Depth: " << depth << std::endl;
	cout << depth * horizontal;
}

void finalPosition2(ifstream& in, string archivo) {

	in.open(archivo, ifstream::in);
	int x = 0, y = 0, aim = 0;

	if (in.good()) {
		string line = "";
		while (!in.eof()) {
			std::getline(in, line);
			string direction = "";
			unsigned pos = line.find(' '); // buscar la posici車n del primer espacio en blanco
			direction = line.substr(0, pos);

			line.erase(0, pos + 1); //eliminamos posici車n de la linea leida

			int desplaz = std::stoi(line, nullptr, 10);
			if (direction == "down") aim += desplaz;
			else if (direction == "up") aim -= desplaz;
			else {
				x += desplaz;
				y += desplaz * aim;
			}

		}
	}
	cout << "Horizontal: " << x << std::endl;
	cout << "Depth: " << y << std::endl;
	cout << x * y;

}