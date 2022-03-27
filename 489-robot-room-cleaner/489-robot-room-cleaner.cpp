/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(Robot& robot, int row, int col, int dir, unordered_map<int, unordered_set<int>>& visited) {
        visited[row].insert(col);
        // cout << row << " " << col << endl;
        robot.clean();
        
        for(int i = dir; i < dir + 4; i ++) {
            int actualDir = i % 4;
            // cout << actualDir << endl;
            int newRow = row + dirs[actualDir][0];
            int newCol = col + dirs[actualDir][1];
            
            if(visited[newRow].count(newCol) == 0 && robot.move()) {
                dfs(robot, newRow, newCol, actualDir, visited);
            }
            robot.turnRight();
        }
        
        // Moves backward one step while maintaining the orientation.
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void cleanRoom(Robot& robot) {
        unordered_map<int, unordered_set<int>> visited;
        dfs(robot, 0, 0, 0, visited);
    }
};