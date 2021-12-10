#ifndef ADVENT10_H
#define ADVENT10_H

constexpr auto CPARENTH = 3;
constexpr auto CCORCHET = 57;
constexpr auto CLLAVES = 1197;
constexpr auto SIMMAYOR = 25137;
constexpr auto IPARENTH = 1;
constexpr auto ICORCHET = 2;
constexpr auto ILLAVES = 3;
constexpr auto ISIMMAYOR = 4;

#include<fstream>;
#include<string>;

void analizarSyntax(std::ifstream& in, std::string archivo);
void analizarSyntax2(std::ifstream& in, std::string archivo);

#endif // !ADVENT10_H

