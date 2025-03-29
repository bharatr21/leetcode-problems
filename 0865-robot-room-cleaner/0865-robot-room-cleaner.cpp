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
    set<pair<int, int>> vis;
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void explore(Robot& robot, int row, int col, int d) {
        robot.clean();
        vis.insert({row, col});
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i = 0; i < 4; i++) {
            int newd = (d + i) % 4;
            int nr = row + dirs[newd].first;
            int nc = col + dirs[newd].second;

            if(!vis.count({nr, nc}) && robot.move()) {
                explore(robot, nr, nc, newd);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        explore(robot, 0, 0, 0);
    }
};