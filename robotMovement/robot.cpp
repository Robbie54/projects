
#include "robot.h"


pair<int, int> Robot::moveRobot(std::pair<int, int>& robotPos){

    char key; 
   
    cout << "w a s d Input: " ;
    cin >> key; 
    int row = 0;
    int coloumn = 0;
    switch(key) {
    case 'w':
        row = -1;
       
        break;
    case 'a':
        coloumn = -1;
        break;
    case 's':
        row = 1;
        break;
    case 'd':
        coloumn =1; 
        break; 
    default:
        cout << "Invalid key please try again! "; 
        moveRobot(robotPos);
    }
    // Calculate new position
    int newRow = robotPos.first + row;
    int newColumn = robotPos.second + coloumn;

    int x = (  gridSize -1)/2;  
        // Check if the new position is within the grid boundaries
    //i have a grid in global frame 0 to 9
    //robot in local(from its spawn) -4 to 4
    //x is 4 
    // - 4 = 0 -3 = 1 -2 =0 


    if (newRow >= -x && newRow <= x && newColumn >= -x && newColumn <= x && currentGrid[newRow+x][newColumn+x] != -1) {
        // Update the robot's position
        robotPos.first = newRow;
        robotPos.second = newColumn;
    } else {
        cout << "Invalid move. Robot cannot move outside the grid. Please try again!" << endl;
        return moveRobot(robotPos); // Recursive call to get a valid move
    }
    
    //if i implement obstacle detection here move robot needs knowledge of the grid 

    return robotPos;
    

}

void Robot::updateGrid(std::vector<std::vector<int>> grid){
    currentGrid = grid; 
}

//since we know goal we could work backwards 

//could return a 
// void Robot::autoMove(std::pair<int, int> robotPos, vector<pair<int,int>> goals, std::vector<std::vector<int>> grid){
//     //maybe a stack for fifo 
    
//     // stack<int> s; 
//     // s.push()

//     //local to global 
//     int x = goals[0].first;
//     int y = goals[0].second;

//     // BFS to calculate distances
//     std::queue<std::pair<int, int>> q;
//     q.push({x, y});
//     grid[x][y] = 0; // Distance of robot to itself is 0

//     while (!q.empty()) {
//         //position from goal 
//         auto current = q.front();
//         q.pop();
//         int row = current.first;
//         int col = current.second;
//         int dist = grid[row][col] + 1;

//         // Explore neighboring cells
//         std::vector<std::pair<int, int>> neighbors = {{row-1, col}, {row+1, col}, {row, col-1}, {row, col+1}};
//         for (const auto& neighbor : neighbors) {
//             int r = neighbor.first;
//             int c = neighbor.second;
//             // if(grid[r][c] < path)
//             if (r >= 0 && r <  gridSize && c >= 0 && c <  gridSize && grid[r][c] > dist) {
//                 grid[r][c] = dist;
//                 q.push(neighbor);
//             }
//         }
//     }
//     return grid; 
// }


