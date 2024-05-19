#include "ConnectFour.h"
#include <iostream>

using namespace std;

char (&ConnectFour::getBoard())[boardSize][boardSize] {
    return board;
}

void ConnectFour::printBoard(char board[boardSize][boardSize]){
    cout << endl;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    cout << "1 2 3 4 5 6 7" << endl;
}

void ConnectFour::turn(){

    int row, coloumn; 
    char piece = 'O';
    bool valid = false;
    turnFlag = !turnFlag; 

    if(turnFlag){
        piece = 'X';
    }
    while(!valid){
        cout << "Please select a coloumn: ";
        cin >> coloumn; 

        if(coloumn > 7 || coloumn < 1){
            cout << "Try again please select numbers between 1 and " << boardSize << endl;
            continue;
        }

        for(int i = boardSize; i >= 0; i--){
            if(board[i][coloumn -1] == '-'){
                board[i][coloumn-1] = piece;
                valid = true; 
                break;
            }
        }
        if(!valid){
        cout << "Coloumn full please try a different one! " << endl;
        }
    }

//     char (&currentBoard)[boardSize][boardSize] = getBoard();
//     int row,coloumn; 
//     bool valid = false; 
//     turnFlag = !turnFlag;
//
// while(!valid){
//     cout << "Plese select a row: ";
//     cin >> row; 
//     while (0>row || row > boardSize){
//         cout << "Please chose numbers 1 - " << boardSize <<"! << \n";
//         cin >> row;
//     }
//     cout << "\n" << "Plese select a coloumn: ";
//     cin >> coloumn; 
//     while (0>coloumn || coloumn > boardSize){
//         cout << "Please chose numbers 1 - " << boardSize << "! << \n";
//         cin >> coloumn;
//     }     
// 
//     // Check if the specified position is already occupied
//     if (currentBoard[row-1][coloumn-1] != '-') {
//         cout << "Position already occupied! Please try again! " << currentBoard[row][coloumn] << endl;   
//         continue; 
//     }
//
//     else if(row == boardSize){
//         valid = true; 
 //       
//     }
//     else if(currentBoard[row][coloumn-1] != '-'){
 //       
//         valid = true;
 //       
//     }
//     else {
//         cout << "Invalid please try again!" << endl;
//     }
// }
//
// playerPos = make_pair(row, coloumn);
//
// if(turnFlag){
//     currentBoard[row-1][coloumn-1] = 'X'; 
// }
// else{
//     currentBoard[row-1][coloumn-1] = 'O'; 
// }  

}


bool ConnectFour::end(){

    if(checkHorizontal() || checkVertical() || checkDiagonal()){
        return true;
    }
    // int row = playerPos.first;
    // int coloumn = playerPos.second;

    //check adjacent squares to piece placed// if same check next in line 

    //these loops check each adjacent square and return squares char if on board
    
    
    // for(int i = row-1; i<=row+1; ++i){
    //     for(int j = coloumn-1; j<=coloumn+1; ++j){
    //         //check pos is in a valid position
    //        // cout << i << " " << j << endl;
    //         if(i >= 0 && i < boardSize+1 && j>=0 && j<boardSize+1){
    //             if (i==row && j==coloumn){
    //                 continue;
    //             }
    //             // Access the character at position (i, j)
    //             char neighborChar = board[i-1][j-1];
    //             cout << "The neighbor char found is at row " << i << " and coloumn " << j << " " << neighborChar << endl;
    //             //if is finding the char on the opposite side 
    //             if(neighborChar == 'O'){
    //                 char nextAdjacent = board[(row-i)+row][(coloumn-j)+coloumn];
    //                 cout << "The next adjacent at row " << ((row-i)+row) << " and coloumn " << ((coloumn-j)+coloumn) << " is " << nextAdjacent << endl;
    //             }

    //             // Perform your checks or actions with neighborChar
    //             //std::cout << "Neighbor at position (" << i << ", " << j << "): " << neighborChar << std::endl;

    //         }
    //     }
    // }


    return false;
}


bool ConnectFour::checkHorizontal(){
    char piece = 'O';
   
    if(turnFlag){
        piece = 'X';
    }
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j<boardSize; j++){
            if(board[i][j] == piece){
                if(board[i][j+1] == piece &&
                   board[i][j+2] == piece &&
                   board[i][j+3] == piece){
                    cout << piece << " Wins!" << endl;
                    return true;
                   }
                   
            }
        }
    }
    return false;
}

bool ConnectFour::checkVertical(){
    char piece = 'O';
   
    if(turnFlag){
        piece = 'X';
    }
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j<boardSize; j++){
            if(board[i][j] == piece){
                if(board[i+1][j] == piece &&
                   board[i+2][j] == piece &&
                   board[i+3][j] == piece){
                    cout << piece << " Wins!" << endl;
                    return true;
                   }
                   
            }
        }
    }
    return false;
}

bool ConnectFour::checkDiagonal(){
    char piece = 'O';
   
    if(turnFlag){
        piece = 'X';
    }
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j<boardSize; j++){
            if(board[i][j] == piece){
                if(board[i-1][j+1] == piece &&
                   board[i-2][j+2] == piece &&
                   board[i-3][j+3] == piece){
                    cout << piece << " Wins!" << endl;
                    return true;
                   }
                   
            }
        }
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j<boardSize; j++){
            if(board[i][j] == piece){
                if(board[i+1][j+1] == piece &&
                   board[i+2][j+2] == piece &&
                   board[i+3][j+3] == piece){
                    cout << piece << " Wins!" << endl;
                    return true;
                   }
                   
            }
        }
    }
    return false;
}
