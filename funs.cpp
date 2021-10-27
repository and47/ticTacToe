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

int ran(int upplim) {
    return rand() % (upplim + 1);
};

int chkVictory(std::vector<int> tiles, bool doPrint /* = true */) {
    // for 2 players - retrieve even and odd
    // sort evens and odds
    // check if any vicConditions fully present in evens or odds
    /*
    std::vector<std::vector<int>> vicConditions = { // for 3x3 board, 8 possible combos (hor, vert, diagonally)
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}, // hor, ver:
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
        {1, 5, 9},   // diag
        {3, 5, 7}
    };
    */
    std::vector<std::vector<int>> vicConditions = genAllVicCombos((int)sqrt(9));
    std::vector<int> evens, odds; // e.g. evens P2, odds P1
    std::vector<char> board(9, 95);  // nine underscores (code 95) for printing empty board
    for (size_t i = 0; i < std::size(tiles); i++)
    {
        if ((i % 2) == 0) {
            evens.push_back(tiles[i]);
            board[tiles[i]-1] = 'X';  // change (surround X and O with) to double-quotes if board is vector<string> not char
        } else {
            odds.push_back(tiles[i]);
            board[tiles[i]-1] = 'O';
        }
    }

    if (doPrint) printBoard(board);

    // check for victory and return the victorer
    //sort(evens.begin(), evens.end()); // for use with binary search if implemented below
    //sort(odds.begin(), odds.end());
    for (auto i : vicConditions)
    {
        if (std::all_of(i.begin(), i.end(), 
                        [odds](int a_elt) { return std::find(odds.begin(), odds.end(), a_elt) != odds.end(); })
           ) return(1);
        if (std::all_of(i.begin(), i.end(),
                        [evens](int a_elt) { return std::find(evens.begin(), evens.end(), a_elt) != evens.end(); })
           ) return(2);
    }

    return(0);
}

// limitation: squared, limited in size board, victory only when full row/col/diag is filled by a player
std::vector<std::vector<int>> genAllVicCombos(int boardWidth) {
    std::vector<std::vector<int>> cmbs((int)(2 * boardWidth + 2)); // 2 for hor/ver + 2 diags
    for (int i = 1; i <= boardWidth; ++i) {  // vers
        for (int j = 0; j < boardWidth; ++j) {
            cmbs[i - 1].push_back(i + j * boardWidth);
        }
    }
    for (int i = 1; i <= boardWidth * boardWidth; i = i + boardWidth) {  // hors
        for (int j = 0; j < boardWidth; ++j) {
            cmbs[boardWidth + (i / boardWidth)].push_back(i + j);
        }
    }
    cmbs[size(cmbs) - 2].resize(boardWidth);  // 2 diags
    std::generate(cmbs[size(cmbs) - 2].begin(), cmbs[size(cmbs) - 2].end(),
                  [boardWidth, n = 1]() mutable { n = n + boardWidth + 1;  return n - boardWidth - 1; });
    cmbs[size(cmbs) - 1].resize(boardWidth);
    std::generate(cmbs[size(cmbs) - 1].begin(), cmbs[size(cmbs) - 1].end(),
                  [boardWidth, n = boardWidth]() mutable { n = n + boardWidth - 1;  return n - boardWidth + 1; });
    return(cmbs);
}

void printBoard(std::vector<char> board) {
    vector<vector<char>> twoD((int)sqrt(board.size()));  // twoD is 2D board (for printing)
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  // alternatively, on linux use system("clear");
                                             // on windows use system("cls"); can use both for cross-platform
    cout << " _ _ _ \n";  // print board's top border
    for (int i = static_cast<int>(std::size(twoD)) - 1; i >= 0; i--)
    {
        std::cout << "|";
        for (size_t j = 0; j < std::size(twoD); ++j)
        {
            twoD[i] = vector<char>(std::size(twoD));
            twoD[i][j] = board[i * std::size(twoD) + j];
            //std::reverse(twoD.begin(), twoD.end());  // think why doesn't work (crashes). without this, had to change outer loop
            //std::swap(twoD[0], twoD[2]);  // think why doesn't work (crashes) with for (size_t i = 0; i < std::size(twoD); ++i)
            std::cout << twoD[i][j] << "|";
        }
        std::cout << "\n";
    }
}
