// TicTacToe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe() : turnFlag(true), board{{'X', 'O', 'X'}, {'-', '-', '-'}, {'-', '-', '-'}}{}
   // board{{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}}
    char (&getBoard())[3][3];
    
    void printBoard(char board[3][3]);

    void turn();

    bool end(char board[3][3]);
    bool draw(); 
    bool turnFlag;
private:
    
    char board[3][3];

    
    
};
#endif // TICTACTOE_H
