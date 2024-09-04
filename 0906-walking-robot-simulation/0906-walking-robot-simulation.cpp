class Solution {
public:
    static const int HASH_FACTOR = 60001;
    int dist(int x, int y) {return (x * x + y * y);}
    int hashc(int x, int y) {return x + HASH_FACTOR * y;}
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstacleSet;
        for(auto obstacle: obstacles) {obstacleSet.insert(hashc(obstacle[0], obstacle[1]));}
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cur = 0, res = 0, x = 0, y = 0;
        for(int command: commands) {
            if(command == -1) {
                cur = (cur + 1) % 4;
            } else if(command == -2) {
                cur = (cur + 3) % 4;
            } else {
                int dx = dirs[cur].first, dy = dirs[cur].second;
                for(int step = 0; step < command; step++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if(obstacleSet.contains(hashc(nx, ny))) break;
                    x = nx;
                    y = ny;
                }
                res = max(res, dist(x, y));
            }
        }
        return res;
    }
};