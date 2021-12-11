#ifndef ADVENT11_H
#define ADVENT11_h

#include<vector>
#include<fstream>
#include<string>

struct Point;
void analizarOctopus(std::ifstream& in, std::string archivo, unsigned steps);
bool operator==(Point lhs, Point rhs);
void analizarOctopus2(std::ifstream& in, std::string archivo, unsigned steps);

#endif
