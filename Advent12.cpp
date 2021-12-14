#include "Advent12.hpp"
#include<map>
#include<iostream>
#include<list>
#include<cctype>

using std::string;
using std::ifstream;
using std::map;
using std::list;
using std::cout;
using std::endl;

void analizarCaves(ifstream& in, string archivo) {
    in.open(archivo);
    map<string, list<string>> relaciones;
    if(in.good()) {
        string line = "";
        while(!in.eof()) { //mapa de relaciones
            std::getline(in, line);
            string part1 = line.substr(0, line.find('-'));
            string part2 = line.substr(line.find('-') + 1);

            relaciones[part1].push_back(part2);
            relaciones[part2].push_back(part1);
        //******debug************//
            //cout << part1 << " " << part2 << endl;
        }

        
        int sol = numPaths("start", relaciones, list<string>());
        cout << "Part 1: " <<  sol << endl;
        sol = numPaths("start", relaciones, map<string, int>());
        cout << "Part 2: " <<  sol << endl;

    }

    in.close();
}

int numPaths(string pos, map<string, list<string>> relaciones, list<string> visited) {
    if(pos == "end") return 1;
    int num = 0;
    if(islower(pos[0])) {
        bool visitado = false;
        for(auto& p : visited) {
            visitado = visitado || p == pos;
        }
        if(visitado) return 0;
    } 
    visited.push_back(pos);
    
    for(auto& p : relaciones[pos]) {
        num += numPaths(p, relaciones, visited);
    }
    return num;
}

int numPaths(string pos, map<string, list<string>> relaciones, map<string, int> visited) {
    if(pos == "end") return 1;
    int num = 0;
    if(islower(pos[0])) {
        if(pos == "start" && visited[pos] == 1) return 0;
        else {
            bool esta = false, yaHay2 = false;
            for(auto it = visited.begin(); it != visited.end(); ++it) {
                
                if(islower((it->first)[0])){
                    esta = esta || (pos == it->first);
                    yaHay2 = yaHay2 || (it->second > 1);
                }
            }
            if(esta && yaHay2) return 0;
        }
    } 
    ++visited[pos];
    
    for(auto& p : relaciones[pos]) {
        num += numPaths(p, relaciones, visited);
    }
    return num;
}