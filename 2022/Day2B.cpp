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
                roundScore += scissors;
            } else if(a == 'B') {
                roundScore += rock;
            } else {
                roundScore += paper;
            }
            
            break;
        
        case 'Y':
            if(a == 'A') {
                roundScore += rock;
            } else if(a == 'B') {
                roundScore += paper;
            } else {
                roundScore += scissors;
            }
            roundScore += DRAW;
            break;

        case 'Z':
            if(a == 'A') {
                roundScore += paper;
            } else if(a == 'B') {
                roundScore += scissors;
            } else {
                roundScore += rock;
            }
            roundScore += WIN;
            break;
        }

        printf("roundScore: %d\n", roundScore);
        myScore += roundScore;
    }

    printf("Total score: %d\n", myScore);
}