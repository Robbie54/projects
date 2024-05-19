#include "headers/MiniMax.h"
#include "headers/TicTacToe.h"
#include <iostream>

using namespace std;



int MiniMax::miniMax(int depth, bool maximizingPlayer, char boardState[3][3]){
    TicTacToe tic;
    // cout << "board in mini " << endl;

    // tic.printBoard(boardState);

    if (maximizingPlayer) {
         double maxEval;
       
        //for eval if player can win in next move eval = 1 if needs two moves eval = 0.5 etc 0.25,0.125


        // Try all possible moves for the maximizing player (X)
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (boardState[i][j] == '-') {
                    boardState[i][j] = 'X';
                    double eval = -1;
                    
                    if(tic.end(boardState)){
                        eval = 1.0/depth;
                        //cout << "a win in max depth of " << depth << " eval is " << eval << endl;
                        //tic.printBoard(boardState);

                    }
                    else {
                        eval = MiniMax::miniMax(depth + 1, false, boardState);
                         
                    }
                    
                    boardState[i][j] = '-'; // Undo the move
                    
                    //how to select best move 
                    if(eval > maxEval){
                        maxEval = eval; 
                        bestRow = i+1;
                        bestColoumn = j+1;
                    }
                }
            }
        }
        
        return maxEval;

     } else {
        
         double minEval;
        // Try all possible moves for the minimizing player (O)
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (boardState[i][j] == '-') {
                    boardState[i][j] = 'O';
                   
                    double eval = -1;
                    if(tic.end(boardState) == true){
                        eval=-1.0/depth;
                       // cout << "a win in min depth of " << depth << " eval is " << eval << endl;

                        //tic.printBoard(boardState);

                       
                    }
                    
                    else {
                        eval = MiniMax::miniMax(depth + 1, true, boardState);
                    }

                    boardState[i][j] = '-'; // Undo the move
                    //minEval = std::min(minEval, eval);
                    if(eval < minEval){
                        minEval = eval; 
                        bestRow = i+1;
                        bestColoumn = j+1;
                    }
                }
            }
        }
        //  cout << "best rc min " << bestRow << " " << bestColoumn << endl;
        //cout << "returning min eval of " << minEval << endl;
        return minEval;
    
     }


}

