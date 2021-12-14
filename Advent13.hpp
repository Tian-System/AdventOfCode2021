#ifndef ADVENT13_H
#define ADVENT13_H

#include<fstream>
#include<string>

struct Point {
    int x;
    int y;

    Point(int row, int col) : x(row), y(col) {}
};

bool operator==(const Point& lhs, const Point& rhs);

bool operator<(const Point& lhs, const Point& rhs);

void analizarManual(std::ifstream& in, std::string archivo);

#endif