#include "Advent07.h"

#include <regex>
#include<iostream>
#include<vector>

using std::ifstream;
using std::string;
using std::regex;
using std::sregex_iterator;
using std::vector;
using std::cout;
using std::endl;

void analizadorCrabs(std::ifstream& in, std::string archivo)
{
	in.open(archivo);
	int ans = 0;
	vector<int> crabs;

	if (in.good()) {
		string pattern = "[[:digit:]]+";
		regex rg(pattern);
		string line = "";
		std::getline(in, line);

		for (sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
			crabs.push_back(std::stoi(it->str()));
		}

		int aux = crabs[0];
		for (auto& crab : crabs) {
			if (crab >= aux) {
				ans += (crab - aux);
			}
			else {
				ans += (aux - crab);
			}
		}

		for (unsigned i = 1; i < crabs.size(); ++i) {
			int curFuel = 0;
			for (unsigned j = 0; j < crabs.size(); ++j) {
				if (crabs[j] >= crabs[i]) {
					curFuel += (crabs[j] - crabs[i]);
				}
				else {
					curFuel += (crabs[i] - crabs[j]);
				}

			}
			if (curFuel < ans) {
				ans = curFuel;
			}

		}
	}

	cout << "*********************************" << endl;
	cout << "Answer: " << ans << endl;
}

void analizadorCrabs2(std::ifstream& in, std::string archivo)
{
	in.open(archivo);
	int ans = 0;
	int max = 0;
	vector<int> crabs;

	if (in.good()) {
		string pattern = "[[:digit:]]+";
		regex rg(pattern);
		string line = "";
		std::getline(in, line);

		for (sregex_iterator it(line.begin(), line.end(), rg), end_it; it != end_it; ++it) {
			int num = std::stoi(it->str());
			if (num > max) max = num;
			crabs.push_back(num);
		}

		
		for (auto& crab : crabs) {
			int sumatorio = 0;
			if (crab >= 0) {
				sumatorio = crab - 0;
			}
			
			ans += (sumatorio * (sumatorio + 1) / 2); //n(n+1)/2

		}

		for (unsigned i = 1; i <= max; ++i) {
			int fuel = 0;

			for (unsigned j = 0; j < crabs.size(); ++j) {
				int sumatorio = 0;
				if (crabs[j] > i) {
					sumatorio = crabs[j] - i;
				}
				else if(crabs[j] < i) {
					sumatorio = i - crabs[j];
				}
				//if(i == 5)cout << (sumatorio * (sumatorio + 1) / 2) << endl;

				fuel += (sumatorio * (sumatorio + 1) / 2);
			}

			if (fuel < ans) {
				ans = fuel;
			}

		}
	}

	cout << "*********************************" << endl;
	cout << "Answer: " << ans << endl;
}
