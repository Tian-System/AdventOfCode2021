#include "Advent11.h"

#include<iostream>
#include<list>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
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


void analizarOctopus(std::ifstream& in, std::string archivo, unsigned steps)
{
	in.open(archivo);
	long flashes = 0;
	vector<vector<int>> map;
	if (in.good()) {
		//creaci¨®n del mapa 
		string line = "";
		while (!in.eof()) {
			vector<int> row;
			std::getline(in, line);
			for (const char& c : line) {
				row.push_back(c - '0');
			}
			map.push_back(row);
		}

		for (unsigned step = 1; step <= steps; ++step) {

			for (auto& row : map) {
				for (auto& col : row) {
					++col;
				}
			}

			list<Point> flashed;
			list<Point> toflash;

			for (unsigned i = 0; i < map.size(); ++i) {
				for (unsigned j = 0; j < map[i].size(); ++j) {
					if (map[i][j] <= 9) continue;
					Point siguiente = Point(i, j);
					bool saltar = false;
					for (auto& punto : flashed) {
						saltar = saltar || (punto == siguiente);
					}
					

					if (saltar) {
						continue;
					}
					toflash.push_back(siguiente);
					while (toflash.size() > 0) {
						Point p = toflash.front();
						toflash.pop_front();
						map[p.row][p.col] = 0;//flashes
						++flashes;
						flashed.push_back(p);

						if (p.row - 1 >= 0 && p.col - 1 >= 0) { //up left
							bool esta = false;
							Point upleft(p.row - 1, p.col - 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == upleft);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == upleft);
							}
							if (!esta) {
								++map[upleft.row][upleft.col];
								if (map[upleft.row][upleft.col] > 9) {

									toflash.push_back(upleft);
								}
							}
						}

						if (p.row - 1 >= 0 && p.col + 1 < map[p.row].size()) { //up right
							bool esta = false;
							Point upright(p.row - 1, p.col + 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == upright);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == upright);
							}
							if (!esta) {
								++map[upright.row][upright.col];
								if (map[upright.row][upright.col] > 9) {

									toflash.push_back(upright);
								}
							}
						}

						if (p.row + 1 < map.size() && p.col - 1 >= 0) { //down left
							bool esta = false;
							Point downleft(p.row + 1, p.col - 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == downleft);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == downleft);
							}
							if (!esta) {
								++map[downleft.row][downleft.col];
								if (map[downleft.row][downleft.col] > 9) {

									toflash.push_back(downleft);
								}
							}
						}

						if (p.row + 1 < map.size() && p.col + 1 < map[p.row].size()) { //down right
							bool esta = false;
							Point downright(p.row + 1, p.col + 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == downright);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == downright);
							}
							if (!esta) {
								++map[downright.row][downright.col];
								if (map[downright.row][downright.col] > 9) {

									toflash.push_back(downright);
								}
							}
						}



						if (p.row - 1 >= 0) { //up
							bool esta = false;
							Point up(p.row - 1, p.col);
							for (auto& punto : flashed) {
								esta = esta || (punto == up);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == up);
							}
							if (!esta) {
								++map[up.row][up.col];
								if (map[up.row][up.col] > 9) {

									toflash.push_back(up);
								}
							}
						}

						if (p.row + 1 < map.size()) { //down
							bool esta = false;
							Point down(p.row + 1, p.col);
							for (auto& punto : flashed) {
								esta = esta || (punto == down);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == down);
							}
							if (!esta) {
								++map[down.row][down.col];
								if (map[down.row][down.col] > 9) {

									toflash.push_back(down);
								}
							}
						}

						if (p.col - 1 >= 0) { //left
							bool esta = false;
							Point left(p.row, p.col - 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == left);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == left);
							}
							if (!esta) {
								++map[left.row][left.col];
								if (map[left.row][left.col] > 9) {

									toflash.push_back(left);
								}
							}
						}

						if (p.col + 1 < map[p.row].size()) { //right
							bool esta = false;
							Point right(p.row, p.col + 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == right);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == right);
							}
							if (!esta) {
								++map[right.row][right.col];
								if (map[right.row][right.col] > 9) {

									toflash.push_back(right);
								}
							}
						}

					}

				}
			}

			
			

			cout << "Flashes step " << step << ": " << flashes << endl;


			for (auto& row : map) {
				for (auto& col : row) {
					cout << col;
				}
				cout << endl;
			}
			cout << endl;
		}

	}


	in.close();
}

void analizarOctopus2(std::ifstream& in, std::string archivo, unsigned steps)
{
	in.open(archivo);
	long flashes = 0;
	vector<vector<int>> map;
	if (in.good()) {
		//creaci¨®n del mapa 
		string line = "";
		while (!in.eof()) {
			vector<int> row;
			std::getline(in, line);
			for (const char& c : line) {
				row.push_back(c - '0');
			}
			map.push_back(row);
		}

		for (unsigned step = 1; step <= steps; ++step) {

			for (auto& row : map) {
				for (auto& col : row) {
					++col;
				}
			}

			list<Point> flashed;
			list<Point> toflash;

			for (unsigned i = 0; i < map.size(); ++i) {
				for (unsigned j = 0; j < map[i].size(); ++j) {
					if (map[i][j] <= 9) continue;
					Point siguiente = Point(i, j);
					bool saltar = false;
					for (auto& punto : flashed) {
						saltar = saltar || (punto == siguiente);
					}


					if (saltar) {
						continue;
					}
					toflash.push_back(siguiente);
					while (toflash.size() > 0) {
						Point p = toflash.front();
						toflash.pop_front();
						map[p.row][p.col] = 0;//flashes
						++flashes;
						flashed.push_back(p);

						if (p.row - 1 >= 0 && p.col - 1 >= 0) { //up left
							bool esta = false;
							Point upleft(p.row - 1, p.col - 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == upleft);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == upleft);
							}
							if (!esta) {
								++map[upleft.row][upleft.col];
								if (map[upleft.row][upleft.col] > 9) {

									toflash.push_back(upleft);
								}
							}
						}

						if (p.row - 1 >= 0 && p.col + 1 < map[p.row].size()) { //up right
							bool esta = false;
							Point upright(p.row - 1, p.col + 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == upright);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == upright);
							}
							if (!esta) {
								++map[upright.row][upright.col];
								if (map[upright.row][upright.col] > 9) {

									toflash.push_back(upright);
								}
							}
						}

						if (p.row + 1 < map.size() && p.col - 1 >= 0) { //down left
							bool esta = false;
							Point downleft(p.row + 1, p.col - 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == downleft);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == downleft);
							}
							if (!esta) {
								++map[downleft.row][downleft.col];
								if (map[downleft.row][downleft.col] > 9) {

									toflash.push_back(downleft);
								}
							}
						}

						if (p.row + 1 < map.size() && p.col + 1 < map[p.row].size()) { //down right
							bool esta = false;
							Point downright(p.row + 1, p.col + 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == downright);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == downright);
							}
							if (!esta) {
								++map[downright.row][downright.col];
								if (map[downright.row][downright.col] > 9) {

									toflash.push_back(downright);
								}
							}
						}



						if (p.row - 1 >= 0) { //up
							bool esta = false;
							Point up(p.row - 1, p.col);
							for (auto& punto : flashed) {
								esta = esta || (punto == up);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == up);
							}
							if (!esta) {
								++map[up.row][up.col];
								if (map[up.row][up.col] > 9) {

									toflash.push_back(up);
								}
							}
						}

						if (p.row + 1 < map.size()) { //down
							bool esta = false;
							Point down(p.row + 1, p.col);
							for (auto& punto : flashed) {
								esta = esta || (punto == down);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == down);
							}
							if (!esta) {
								++map[down.row][down.col];
								if (map[down.row][down.col] > 9) {

									toflash.push_back(down);
								}
							}
						}

						if (p.col - 1 >= 0) { //left
							bool esta = false;
							Point left(p.row, p.col - 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == left);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == left);
							}
							if (!esta) {
								++map[left.row][left.col];
								if (map[left.row][left.col] > 9) {

									toflash.push_back(left);
								}
							}
						}

						if (p.col + 1 < map[p.row].size()) { //right
							bool esta = false;
							Point right(p.row, p.col + 1);
							for (auto& punto : flashed) {
								esta = esta || (punto == right);
							}
							for (auto& punto : toflash) {
								esta = esta || (punto == right);
							}
							if (!esta) {
								++map[right.row][right.col];
								if (map[right.row][right.col] > 9) {

									toflash.push_back(right);
								}
							}
						}

					}

				}
			}

			bool allFlash = true;

			for (auto& row : map) {
				for (auto& col : row) {
					allFlash = allFlash && (col == 0);
				}
				
			}

			if (allFlash) {
				cout << "Step " << step << ": all flash" << endl;
				break;
			}
			
		}

	}


	in.close();
}