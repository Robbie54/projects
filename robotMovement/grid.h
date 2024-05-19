#include <vector>
#include <iostream>
#include <queue>
#include <iomanip> // For std::setw

#define GRIDSIZE 9 

// ANSI escape codes for text color
#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std; 

class Grid { 
    private: 
        const int gridSize;
        std::vector<std::vector<int>> emptyGrid; 
        std::vector<std::vector<int>> gridWObstacles; 

    public:
        Grid(int gridSize) : gridSize(gridSize) {
            emptyGrid = initialiseEmptyGrid();
            
        }
        void printGrid(std::vector<std::vector<int>> grid);

        std::vector<std::vector<int>> initialiseEmptyGrid();
        void updateObstacleGrid(const std::vector<std::pair<int, int>>& obstacles);
        std::vector<std::vector<int>> getGrid(); 

        std::vector<std::vector<int>> bfs(const std::vector<std::pair<int, int>>& obstacles, pair<int,int> robotPos);

        std::vector<std::vector<int>> addGoalsToGrid(std::vector<std::vector<int>>& grid, vector<pair<int,int>> goals);


    
};