#include "Advent14.hpp"

#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using std::ifstream;
using std::string;
using std::map;
using std::vector;
using std::cout;
using std::getline;
using std::endl;
using std::set;

void analizarReaccionesQ(ifstream& in, string archivo, int steps) {
    in.open(archivo);
    string materials = "";
    string line = "";
    map<string, char> reactions;
    
    if(in.good()) {
        getline(in, materials); //1st line
        getline(in, line); //empty line

        while(!in.eof()) {
            getline(in, line);
            string reactio = line.substr(0, 2);
            char result = line.back();
            // debuag cout << reactio << " "  << result << endl;
            reactions.insert({reactio, result});
        }

        for(int i = 1; i <= steps; ++i) {
            string aux = "";
            for(unsigned pos = 0; pos < materials.size() - 1; ++pos) {
                string subs = materials.substr(pos, 2);
                char res = reactions[subs];
                aux += subs[0];
                aux += res;
                if(pos + 1 == materials.size() -1) aux += subs[1];
            }
            materials = aux;
            //cout << materials << " " << materials.size() << endl;
        }
        
        vector<unsigned long long> letteTimes(26, 0);
        for(auto& c : materials) {
            ++letteTimes[c - 'A'];
        }
        std::sort(letteTimes.begin(), letteTimes.end());
        unsigned long long least = 0;
        for(auto& num : letteTimes) {
            least = num;
            if(num != 0) break;
        }
        
        cout << "Part 1" << endl;
        cout << "Answer: " << letteTimes[25] - least << endl;
    }
    in.close();

}

void analizarReaccionesQ2(ifstream& in, string archivo, int steps) {
    in.open(archivo);
    string materials = "";
    string line = "";
    map<string, char> reactions;
    map<string, long long> reactionNums;
    
    if(in.good()) {
        getline(in, materials); //1st line
        getline(in, line); //empty line

        while(!in.eof()) {
            getline(in, line);
            string reactio = line.substr(0, 2);
            char result = line.back();
            // debuag cout << reactio << " "  << result << endl;
            reactions.insert({reactio, result});
            
        }
        for(unsigned pos = 0; pos < materials.size() - 1; ++pos) {
            string subs = materials.substr(pos, 2);
            ++reactionNums[subs]; //cuantas parejas en un principio
        }

        for(int i = 1; i <= steps; ++i) {
            
            map<string, long long> aux;
            for(auto it = reactionNums.begin(); it != reactionNums.end(); ++it) {
                char res = reactions[it->first];
                //cout << it->first << endl;
                string newP1 = (it->first).substr(0,1) + res;
                string newP2 = res + (it->first).substr(1,1);
                //cout << newP1 << " " << newP2 << endl;
                
                aux[newP1] += it->second;
                aux[newP2] += it->second; 
                
                //cout << it->first << " " << it->second << endl;
            }
            //cout << materials << " " << materials.size() << endl;
            
            
            reactionNums = aux;
        }
        
        vector<unsigned long long> letteTimes(26, 0);
        
        for(auto& pareja : reactionNums) {
            letteTimes[((pareja.first)[1]) - 'A'] += pareja.second;
        }
        
        ++letteTimes[materials[0] - 'A'];
        std::sort(letteTimes.begin(), letteTimes.end()); /*The second letter is always being shared with another pair
                                                        we count only the second pair, and after we add one to the first lett
                                                        */
        
        unsigned long long least = 0;
        for(auto& num : letteTimes) {
            least = num;
            if(num != 0) break;
        }
        
        
        cout << "Part 2" << endl;
        cout << "Answer: " << (letteTimes.back() -  least) << endl;  
    }
    in.close();
    //5208377027195
    //5208377027195
}

int main() {

    ifstream in;
    analizarReaccionesQ2(in, "Advent14.txt", 40);
}