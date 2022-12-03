#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>

using std::getline;
using std::ifstream;
using std::string;
using std::set;
using std::cout;
using std::endl;


int main() {

    ifstream in;
    in.open("data.txt");

    string line1 = "";
    string line2 = "";
    string line3 = "";
    int totalSum = 0, priority = 0;

    while(getline(in, line1)) {

        getline(in, line2);
        getline(in, line3);
        
        cout << line1 << endl;
        cout << line2 << endl;
        cout << line3 << endl;
        cout << endl;

        set<char> first;
        set<char> second;
        set<char> third;

        for(auto c : line1) {
            first.insert(c);
        }

        for(auto c: line2) {
            second.insert(c);
        }

        for(auto c: line3) {
            third.insert(c);
        }

        for(char c : first) {
            for(char d : second) {
                if(c == d) {
                    for(char e : third) {
                        if(e == c) {
                            if(isupper(c)) {
                                priority = c - 38;
                            } else {
                                priority = c - 'a' + 1;
                            }
                            printf("priority: %d\n", priority);
                            totalSum += priority;
                        }   
                    }
                }   
            }
        }
    }

    printf("Total sum: %d\n", totalSum);
}