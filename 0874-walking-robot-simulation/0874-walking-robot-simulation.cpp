class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0; // Initial coordinates
        int dir = 0; // 0 = north, 1 = east, 2 = south, 3 = west
        int maxDistance = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else {
                // Move forward in the current direction
                for (int i = 0; i < command; ++i) {
                    int nextX = x, nextY = y;
                    if (dir == 0) nextY += 1; // Moving north
                    else if (dir == 1) nextX += 1; // Moving east
                    else if (dir == 2) nextY -= 1; // Moving south
                    else if (dir == 3) nextX -= 1; // Moving west
                    
                    // Check if the next position is an obstacle
                    bool isObstacle = false;
                    for (const auto& obstacle : obstacles) {
                        if (obstacle[0] == nextX && obstacle[1] == nextY) {
                            isObstacle = true;
                            break;
                        }
                    }
                    
                    if (!isObstacle) {
                        x = nextX;
                        y = nextY;
                        maxDistance = max(maxDistance, x * x + y * y);
                    } else {
                        break; // Stop moving if there's an obstacle
                    }
                }
            }
        }
        
        return maxDistance; // Return the maximum Euclidean distance squared
    }
};
