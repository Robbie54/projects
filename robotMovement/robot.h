
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std; 

class Robot{
    private: 
        const int gridSize;
        std::vector<std::vector<int>> currentGrid; 

        // Robot () {} //prevent initialising without a gridSize 

    public:

        Robot(int gridSize) : gridSize(gridSize) {}
        pair<int, int> moveRobot(std::pair<int, int>& robotPos);
        void updateGrid(std::vector<std::vector<int>> grid);

        // void autoMove(std::pair<int, int> robotPos, vector<pair<int,int>> goals);

};
