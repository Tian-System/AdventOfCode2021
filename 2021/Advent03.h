#ifndef ADVENT03_H
#define ADVENT03_H

#include<fstream>
#include<string>
#include<bitset>
#include<vector>

void analizarBits(std::ifstream&, std::string);

//tamaño modificable si el bitset es de otro tamaño
unsigned bitMasFrecuente(std::vector<std::bitset<12>>&, unsigned pos, unsigned bit);

unsigned long oxigen(std::ifstream&, std::string);

unsigned long co2(std::ifstream&, std::string);

#endif // !ADVENT03_H

