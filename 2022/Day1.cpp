#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using std::ifstream;
using std::getline;
using std::string;
using std::priority_queue;

int main() {

    ifstream in;
    in.open("data.txt");
    string line = "";
    int sum = 0;

    priority_queue<long> lista = priority_queue<long>();

    while(getline(in, line)) {
        if(line == "") {
            lista.push(sum);
            sum = 0;
            continue;
        }

        long calories = std::stol(line);
        sum += calories;
    }

    long top1 = lista.top();

    printf("Max Calories: %ld\n", top1);

    lista.pop();

    long top2 = lista.top();
    lista.pop();

    long top3 = lista.top();
    lista.pop();

    long totalTop = top1 + top2 + top3;
    printf("Sum calores of top 3: %ld\n", totalTop);

    return 0;
}