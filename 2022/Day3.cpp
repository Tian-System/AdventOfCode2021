#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>

using std::getline;
using std::ifstream;
using std::string;
using std::set;


int main() {

    ifstream in;
    in.open("data.txt");

    string line = "";
    int totalSum = 0, priority = 0;

    while(getline(in, line)) {
        
        set<char> first, second;

        for(int i = 0; i < line.size()/2; ++i) {
            first.insert(line[i]);
        }

        for(int i = line.size()/2; i < line.size(); ++i) {
            second.insert(line[i]);
        }

        for(char c : first) {
            for(char d : second) {
                if(c == d) {

                    if(isupper(c)) {
                        priority = c - 38;
                    } else {
                        priority = c - 'a' + 1;
                    }

                    totalSum += priority;
                }
            }
        }
    }

    printf("Total sum: %d\n", totalSum);
}