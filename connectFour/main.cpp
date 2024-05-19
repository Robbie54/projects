#include <iostream>

#include "ConnectFour.h"

using namespace std;

int main() {
    ConnectFour game;
    char (&board)[boardSize][boardSize] = game.getBoard();
    game.printBoard(board);

    bool winner = false;
    while(!winner){
        game.turn();
        game.printBoard(board);

        winner = game.end();
    }

    return 0;
}


