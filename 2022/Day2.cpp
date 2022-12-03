#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

const int rock = 1;
const int paper = 2;
const int scissors = 3;
#define DRAW 3
#define WIN 6

int main() {
    char a, b;

    ifstream in;
    in.open("data.txt");

    string line = "";
    int myScore = 0;

    while(getline(in, line)) {
        a = line[0];
        b = line[2];

        printf("%c, %c\n", a, b);

        int roundScore = 0;
        switch (b)
        {
        case 'X':
            if(a == 'A') {
                roundScore += DRAW; 
            } else if(a == 'C') {
                roundScore += WIN;
            }
            roundScore += rock;
            break;
        
        case 'Y':
            if(a == 'A') {
                roundScore += WIN;
            } else if(a == 'B') {
                roundScore += DRAW;
            }
            roundScore += paper;
            break;

        case 'Z':
            if(a == 'B') {
                roundScore += WIN;
            } else if(a == 'C') {
                roundScore += DRAW;
            }
            roundScore += scissors;
            break;
        }

        printf("roundScore: %d\n", roundScore);
        myScore += roundScore;
    }

    printf("Total score: %d\n", myScore);
}