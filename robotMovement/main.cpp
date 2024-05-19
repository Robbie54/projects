//THIS CODE uses bfs to show how far square is from robot 

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

#include "grid.h"
#include "robot.h"

using namespace std; 

#define GRIDSIZE 9


int main() {
    pair<int,int> robotPos = {0,0};
    //obstacles relative in global frame 
    std::vector<std::pair<int, int>> obstacles = {{1,1},{3,2},{3,3},{4,3},{2,3},{3,1},{6,6},{3,3}};//, {0, -1},{2,3},{2,4},{4,0},{4,4},{-4,-4}}; // Example obstacles 
    
    vector<pair<int,int>> goals = {{1,2},{8,4} };
    Grid grid(GRIDSIZE);
    Robot robot(GRIDSIZE);
   
    std::vector<std::vector<int>> currentGrid = grid.bfs(obstacles, robotPos);

    robot.updateGrid(grid.getGrid());
     grid.printGrid(currentGrid);
    while(1){
        robot.moveRobot(robotPos);
        // cout << "Robot pos " << robotPos.first << " " << robotPos.second << endl; 
        currentGrid = grid.bfs(obstacles,robotPos);
        grid.addGoalsToGrid(currentGrid, goals);
        grid.printGrid(currentGrid);

    }

    return 0;
}
