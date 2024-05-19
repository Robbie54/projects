#include "grid.h"



void Grid::printGrid(std::vector<std::vector<int>> grid){
    
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            if (grid[i][j] == -1) {
                cout << ANSI_COLOR_RED << setw(2) << " X " << ANSI_COLOR_RESET; // Print 'X' in red
            } else if (grid[i][j] == std::numeric_limits<int>::max()) {
                cout << "- ";
            } else if(grid[i][j] == 0){
                //  std::cout << setw(3) << grid[i][j] << "|";
                cout << ANSI_COLOR_GREEN << setw(2) << " 0 " << ANSI_COLOR_RESET;
            } else if(grid[i][j] == std::numeric_limits<int>::min()) {
                cout << ANSI_COLOR_GREEN << setw(2) << " # " << ANSI_COLOR_RESET;
            } else {
                cout << setw(2) << grid[i][j] << " ";
            }
        }
        cout << std::endl;
    }
}

std::vector<std::vector<int>> Grid::initialiseEmptyGrid(){
    // Fill the grid with maximum distances
    std::vector<std::vector<int>> grid(GRIDSIZE, std::vector<int>(GRIDSIZE, 0));

    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            grid[i][j] = std::numeric_limits<int>::max();
        }
    }

    return grid; 
}

void Grid::updateObstacleGrid(const std::vector<std::pair<int, int>>& obstacles){
    // Mark obstacles
    gridWObstacles = emptyGrid;

    for (const auto& obstacle : obstacles) {
        int row = obstacle.first;
        int col = obstacle.second;
        if (row >= 0 && row <  gridSize && col >= 0 && col <  gridSize) {
            gridWObstacles[row][col] = -1; // Set obstacle
        }
    }

}



 std::vector<std::vector<int>> Grid::bfs(const std::vector<std::pair<int, int>>& obstacles, pair<int,int> robotPos) {
    updateObstacleGrid(obstacles); 
    vector<vector<int>> grid = gridWObstacles; 
    
    cout << endl;

    //local to global 
    int x = (gridSize - 1)/2 + robotPos.first;
    int y = (gridSize - 1)/2 + robotPos.second;

    

    // BFS to calculate distances
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = 0; // Distance of robot to itself is 0

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int row = current.first;
        int col = current.second;
        int dist = grid[row][col] + 1;

        // Explore neighboring cells
        std::vector<std::pair<int, int>> neighbors = {{row-1, col}, {row+1, col}, {row, col-1}, {row, col+1}};
        for (const auto& neighbor : neighbors) {
            int r = neighbor.first;
            int c = neighbor.second;
            if (r >= 0 && r <  gridSize && c >= 0 && c <  gridSize && grid[r][c] > dist) {
                grid[r][c] = dist;
                q.push(neighbor);
            }
        }
    }
    return grid; 
}


std::vector<std::vector<int>> Grid::getGrid(){
    if(gridWObstacles.empty()) { 
        cout << "GRID NOT INITIALISED! " << endl;
        return emptyGrid;
    }
   return gridWObstacles;
}

std::vector<std::vector<int>> Grid::addGoalsToGrid(std::vector<std::vector<int>> &grid, vector<pair<int,int>>goals ){
        for(auto goal : goals){
            grid[goal.first][goal.second] = std::numeric_limits<int>::min();
        }

        return grid; 
}
