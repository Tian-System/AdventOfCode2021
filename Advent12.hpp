#ifndef ADVENT12_H
#define ADVENT12_H

#include<fstream>
#include<string>
#include<map>
#include<list>

void analizarCaves(std::ifstream& in, std::string archivo);
int numPaths(std::string pos, std::map<std::string, std::list<std::string>> relaciones, std::list<std::string> visited);

int numPaths(std::string pos, std::map<std::string, std::list<std::string>> relaciones, std::map<std::string, int> visited);

#endif