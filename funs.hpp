#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


int ran(int upplim);

int chkVictory(std::vector<int> tiles, bool doPrint = true);

std::vector<std::vector<int>> genAllVicCombos(int boardWidth);

void printBoard(std::vector<char> board);
