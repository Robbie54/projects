// TicTacToe.cpp
#include "headers/TicTacToe.h"
#include <iostream>

using namespace std;

char (&TicTacToe::getBoard())[3][3] {
    return board;
}

void TicTacToe::printBoard(char board[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void TicTacToe::turn(){
    int row, coloumn; 
    bool valid = false;
  
    turnFlag = !turnFlag; 

    if(turnFlag){
        cout << "X's Turn ";
    }
    else {
        cout << "O's Turn ";
    }

    while(valid == false){
        cout << "Please select a row: ";
        cin >> row; 
        while (0>row || row > 3){
            cout << "Please chose numbers 1 - 3! << \n";
            cin >> row;
        }
        cout << "\n" << "Please select a coloumn: ";
        cin >> coloumn; 
        while (0>coloumn || coloumn > 3){
            cout << "Please chose numbers 1 - 3! << \n";
            cin >> coloumn;
        }
        if(board[row-1][coloumn-1] == '-'){
            valid = true;
        }  
        else {
            cout << "Try again this spot is taken! ";
        }
    };
    
    

    if(turnFlag){
        board[row-1][coloumn-1] = 'X';
    }
    else{
        board[row-1][coloumn-1] = 'O';
    }

    printBoard(board); 
}

bool TicTacToe::end(char board[3][3]){
   // Check rows for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return true;  // Row has three consecutive symbols, indicating a win
        }
    }

    // Check columns for a win
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') {
            return true;  // Column has three consecutive symbols, indicating a win
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')) {
        return true;  // Diagonal has three consecutive symbols, indicating a win
    }

    return false;  // No win condition found
}

bool TicTacToe::draw(){
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(board[i][j] == '-'){
                return false;
            }
        }
    }
    
    return true;

}







