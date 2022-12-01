#include "Advent13.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <list>
#include <vector>
#include <set>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::regex;
using std::sregex_iterator;
using std::list;
using std::vector;
using std::set;

int main() {
    ifstream in;

    analizarManual(in, "Advent13.txt");
}

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator<(const Point& lhs, const Point& rhs) {
    if(lhs.x < rhs.x) return true;
    else if(lhs.x == rhs.x && lhs.y < rhs.y) return true;
    return false;
}

void analizarManual(ifstream& in, string archivo) {
    in.open(archivo);
    list<Point> puntos;
    vector<string> fold;
    set<Point> res;
    
    if(in.good()) {
        string pattern = "[[:digit:]]+";
        regex rg(pattern);
        string line = "";
        while(!in.eof()) {
            std::getline(in, line);
            if(line == "") break; //si se trata de una línea en blanco
            vector<int> pos;
            for(sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
                pos.push_back(std::stoi(it->str()));
            }
            puntos.push_back(Point(pos[0], pos[1]));
            //debug
            //cout << pos[0] << ", " << pos[1] << endl;
        }
        while(!in.eof()) {
            std::getline(in, line);
            line.erase(0, line.find_last_of(' ') + 1);
            fold.push_back(line);
            //debug
            //cout << line << endl;
        }

        //part 1
        int numToFold = std::stoi(fold[0].substr(fold[0].find('=')+1));
        char xOrY = fold[0][0];
        if(xOrY == 'x') {
            for(auto it = puntos.begin(); it != puntos.end(); ++it) {
                if(it->x < numToFold) res.insert(*it);
                else if(it->x > numToFold) {
                    int dif = it->x - numToFold;
                    dif = numToFold - dif;
                    it->x = dif;
                    res.insert(*it);
                }
            }
        } else {
            for(auto& p : puntos) {
                if(p.y < numToFold) res.insert(p);
                else if(p.y > numToFold) {
                    int dif = p.y - numToFold;
                    dif = numToFold - dif;
                    p.y = dif;
                    res.insert(p);
                }
            }
        }

        cout << "*********Part 1***********" << endl;
        cout << "Answer: " << res.size() << endl;

        for(unsigned i = 1; i < fold.size(); ++i) {
            set<Point> aux;
            numToFold = std::stoi(fold[i].substr(fold[i].find('=')+1));
            xOrY = fold[i][0];
            cout << xOrY << " " << numToFold << endl;
            if(xOrY == 'x') {
                for(auto& p : res) {
                    if(p.x < numToFold) aux.insert(p);
                    else if(p.x > numToFold) {
                        int dif = p.x - numToFold;
                        dif = numToFold - dif;
                        
                        aux.insert(Point(dif, p.y));
                    }
                }
            } else {
                for(auto& p : res) {
                    if(p.y < numToFold) aux.insert(p);
                    else if(p.y > numToFold) {
                        int dif = p.y - numToFold;
                        dif = numToFold - dif;
                        
                        aux.insert(Point(p.x, dif));
                    }
                }
            }
            res = aux;
            cout << res.size() << endl;
        }

        cout << endl;

        int maxX = -1;
        int maxY = -1;
        for(auto& p : res) {
            if(maxX < p.x) maxX = p.x;
            if(maxY < p.y) maxY = p.y;
        }
        cout << maxX << " " << maxY << endl;

        for(int i = 0; i <= maxX; ++i) {    //due to the < operator, some characters are printed in diferent position xd
            for(int j = 0; j <= maxY; ++j) {
                if(res.find(Point(i, j)) != res.end()) cout << "*";
                else cout << " "; 
            }
            cout << endl;
        }
        

        
    }
    in.close();
}