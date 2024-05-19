#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#define boardSize 7

#include <utility>


class ConnectFour {
public:
    ConnectFour() : turnFlag(false){
        for(int i = 0; i < boardSize; i++){
            for(int j=0; j<boardSize; j++){
                board[i][j] = '-';
            }
        }};

    char (&getBoard())[boardSize][boardSize];
    
    void printBoard(char board[boardSize][boardSize]);  
    
    void turn();

    bool end();

private:
    bool turnFlag; 
    char board[boardSize][boardSize];
    std::pair <int, int> playerPos; 
    bool checkHorizontal();
    bool checkVertical();
    bool checkDiagonal();
    
};
#endif 
