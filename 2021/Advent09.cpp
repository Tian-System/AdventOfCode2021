#include "Advent09.h"   //TY TurkeyDev
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::list;

struct Point {
    int row;
    int col;
    Point(int x, int y) {
        row = x;
        col = y;
    }

    Point(unsigned x, unsigned y) {
        row = x;
        col = y;
    }
    
};

bool operator==(Point lhs, Point rhs) {
    return lhs.col == rhs.col && lhs.row == rhs.row;
}

void analizarLavaTubes(std::ifstream& in, std::string archivo) {
    in.open(archivo);
    vector<vector<int>> map;
    vector<int> ans;
    int res = 0;
    if(in.good()) {
        string pattern = "[:digit:]";
        string line;

        //creación del vector de vectores de enteros
        while(!in.eof()) {
            std::getline(in, line);
            vector<int> fila;
            for(auto& c : line) {
                int num = c - '0';
                fila.push_back(num);
            }
            map.push_back(fila);
        }

        for(unsigned i = 0; i < map.size(); ++i) {
            for(unsigned j = 0; j < map[i].size(); ++j) {
                int val = map[i][j];
                if(i == 0 || j == 0 || i == map.size() - 1 || j == map[i].size() - 1) {
                    //si i = j = 0
                    
                    if(i == 0 && j == 0) {
                        if(val < map[i][j + 1] && val < map[i + 1][j]) {
                            ans.push_back(val);
                        }
                    } else if(i == 0 && j == map[i].size() - 1) { //si (0, n - 1)
                        if(val < map[i][j - 1] && val < map[i + 1][j]) {
                            ans.push_back(val);
                        }
                    } else if(i == map.size() - 1 && j == 0) { //si (n - 1, 0)
                        if(val < map[i - 1][j] && val < map[i][j + 1]) {
                            ans.push_back(val);
                        }
                    } else if(i == map.size() - 1 && j == map[i].size() - 1) { //si (n - 1, n - 1)
                        if(val < map[i - 1][j] && val < map[i][j - 1]) {
                            ans.push_back(val);
                        }
                    } else if(i == 0) { //si es la fila 0
                        if(val < map[i][j-1] && val < map[i][j+1] && val < map[i+1][j]) {
                            ans.push_back(val);
                        }
                    } else if(j == 0) { //si es la columna 0
                        if(val < map[i-1][j] && val < map[i+1][j] && val < map[i][j+1]) {
                            ans.push_back(val);
                        }
                    } else if(i == map.size() - 1) { //si es la fila n-1
                        if(val < map[i][j-1] && val < map[i][j+1] && val < map[i-1][j]) {
                            ans.push_back(val);
                        }
                    } else {    //si es la columna n-1
                        if(val < map[i][j-1] && val < map[i-1][j] && val < map[i+1][j]) {
                            ans.push_back(val);
                        }
                    }

                } else {
                    if(val < map[i-1][j] && val < map[i][j-1] && val < map[i][j+1] && val < map[i+1][j]) {
                        ans.push_back(val);
                    }
                }

            }
        }

        for(const auto& n : ans) {
            res += (n+1);
        }


    }

    cout << "******************************" << endl;
    cout << "Answer: " << res << endl;
}

void analizarLavaTubes2(std::ifstream& in, std::string archivo) {
    in.open(archivo);
    vector<vector<int>> map;
    list<Point> lowest;
    list<unsigned> basins;
    int res = 1;

    if (in.good()) {
        string pattern = "[:digit:]";
        string line;

        //creación del vector de vectores de enteros
        while (!in.eof()) {
            std::getline(in, line);
            vector<int> fila;
            for (auto& c : line) {
                int num = c - '0';
                fila.push_back(num);
            }
            map.push_back(fila);
        }

        for (unsigned i = 0; i < map.size(); ++i) {
            for (unsigned j = 0; j < map[i].size(); ++j) {
                int val = map[i][j];
                if (i == 0 || j == 0 || i == map.size() - 1 || j == map[i].size() - 1) {
                    //si i = j = 0

                    if (i == 0 && j == 0) {
                        if (val < map[i][j + 1] && val < map[i + 1][j]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else if (i == 0 && j == map[i].size() - 1) { //si (0, n - 1)
                        if (val < map[i][j - 1] && val < map[i + 1][j]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else if (i == map.size() - 1 && j == 0) { //si (n - 1, 0)
                        if (val < map[i - 1][j] && val < map[i][j + 1]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else if (i == map.size() - 1 && j == map[i].size() - 1) { //si (n - 1, n - 1)
                        if (val < map[i - 1][j] && val < map[i][j - 1]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else if (i == 0) { //si es la fila 0
                        if (val < map[i][j - 1] && val < map[i][j + 1] && val < map[i + 1][j]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else if (j == 0) { //si es la columna 0
                        if (val < map[i - 1][j] && val < map[i + 1][j] && val < map[i][j + 1]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else if (i == map.size() - 1) { //si es la fila n-1
                        if (val < map[i][j - 1] && val < map[i][j + 1] && val < map[i - 1][j]) {
                            lowest.push_back(Point(i, j));
                        }
                    }
                    else {    //si es la columna n-1
                        if (val < map[i][j - 1] && val < map[i - 1][j] && val < map[i + 1][j]) {
                            lowest.push_back(Point(i, j));
                        }
                    }

                }
                else {
                    if (val < map[i - 1][j] && val < map[i][j - 1] && val < map[i][j + 1] && val < map[i + 1][j]) {
                        lowest.push_back(Point(i, j));
                    }
                }

            }
        }

        //BFS
        for (auto& point : lowest) {
            list<Point> visited;
            list<Point> toVisit;
            toVisit.push_back(point);
            while (toVisit.size() > 0) {
                Point p = toVisit.front();
                toVisit.pop_front();
                bool yaEsta = false;
                for (auto& p1 : visited) { //si visited contiene aux
                    yaEsta = yaEsta || p1 == p;
                }
                if (yaEsta) {
                    continue;
                }

                visited.push_back(p);
                
                
                int row = p.row, col = p.col;
                
                

                if ((row - 1 >= 0) && (map[row - 1][col] != 9)) {
                    Point aux(row - 1, col);
                    bool esta = false;
                    for (auto& punto : visited) { //si visited contiene aux
                        esta = esta || p == aux;
                    }
                    if (!esta) {
                        toVisit.push_back(aux);
                    }
                }
                if ((row + 1) < map.size() && map[row + 1][col] != 9) {
                    Point aux(row + 1, col);
                    bool esta = false;
                    for (auto& punto : visited) { //si visited contiene aux
                        esta = esta || p == aux;
                    }
                    if (!esta) {
                        toVisit.push_back(aux);
                    }
                }
                if ((col - 1) >= 0 && map[row][col - 1] != 9) {
                    Point aux(row, col - 1);
                    bool esta = false;
                    for (auto& punto : visited) { //si visited contiene aux
                        esta = esta || p == aux;
                    }
                    if (!esta) {
                        toVisit.push_back(aux);
                    }
                }
                if ((col + 1) < map[row].size() && map[row][col + 1] != 9) {
                    Point aux(row, col + 1);
                    bool esta = false;
                    for (auto& punto : visited) { //si visited contiene aux
                        esta = esta || p == aux;
                    }
                    if (!esta) {
                        toVisit.push_back(aux);
                    }
                }

            }
            basins.push_back(visited.size());

        }
        basins.sort(std::greater<int>());

    }
    for (unsigned i = 0; i < 3; ++i) {
        cout << basins.front() << endl;
        res *= basins.front();
        basins.push_back(basins.front());
        basins.pop_front();
    }
    cout << "******************************" << endl;
    cout << "Answer: " << res << endl;
}


