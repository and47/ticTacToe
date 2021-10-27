#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "funs.hpp"
//#include <cctype>

    // to-do:
    // compute vicConditions programmatically (more universally)
    // print/display board in a separate function outside of vicConditions
    // use classes, create game.launch function for control
    // change user input 1-9 to proper board coordinates supporting matrix ops
    // improve QWE-C input (instead of 1-9 input)
    // support AI
    // support empty player name for AI
    // support randomness in AI moves
    // support any number of players
    // any size of board, unlimited (dynamic) board
    // use const ref where copying isn't necessary
    // cmake, unit tests, git, cross platform (test compilation), github action + cmake

using namespace std;

int main()
{
    std::srand((unsigned int) std::time(0));

    string P1, P2, userInput;
    cout << "\nYet Another Tic Tac Toe" << endl;
    cout << "\nPlayer 1 name? (Enter any text or enter AI and hit Enter!)" << endl;
    cin >> P1;
    cout << "\nPlayer 2 name? (Enter any text or enter AI and hit Enter!)" << endl;
    cin >> P2;

    std::vector<string> PS = { P1, P2 };

    cout << "Use below letter keys or numpad:" << endl;
    cout << " _ _ _    _ _ _" << endl;
    cout << "|Q|W|E|  |7|8|9|" << endl;
    cout << "|A|S|D|  |4|5|6|" << endl;
    cout << "|Z|X|C|  |1|2|3|" << endl;

    int tile, totalTurns = 0, victory = 0, whosturn = ran(1);
    std::vector<int> tiles;

    while ((totalTurns < 9) && (victory == 0)) {

        cout << "\n\nTurn: " << PS[whosturn] << ". Enter a tile and hit Enter!" << endl;
        cin >> userInput;

        std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return std::toupper(c); });
        map<string, int> keymap{ 
            { "Q", 7 }, { "W", 8 }, { "E", 9 },
            { "A", 4 }, { "S", 5 }, { "D", 6 },
            { "Z", 1 }, { "X", 2 }, { "C", 3 } };
        tile = keymap[userInput];
        if (tile == 0) tile = stoi(userInput);  // for future boards > 3x3, handle exception 

        while ((std::find(tiles.begin(), tiles.end(), tile) != tiles.end()) ||
               (tile < 1) ||
               (tile > 9))
        {
            std::cout << "Choose another tile!" << endl;
            cin >> userInput;
            std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) { return std::toupper(c); });
            tile = keymap[userInput];
            if (tile == 0) tile = stoi(userInput); 
        }

        tiles.push_back(tile);

        victory = chkVictory(tiles);
        if (victory > 0) cout << "\n\n Wins: " << PS[whosturn] << "!\n\n";

        if (whosturn > 0) --whosturn; else ++whosturn;
        ++totalTurns;
    }
    if ((totalTurns == 9) && (victory == 0)) cout << "\n\n Draw!!!\n\n";
};
