class Solution {
public:
    bool isValid(int x, int y, int m, int n) { return (x >= 0 && x < m && y >=0 && y < n);}
    void wallsAndGates(vector<vector<int>>& rooms) {
        int INF = 2147483647;
        int m = rooms.size(), n = rooms[0].size();
        queue<tuple<int, int, int>> q;
        vector<pair<int, int>> dirs = {{0, 1}, {0 ,-1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) {
                    q.push({0, i, j});
                }
            }
        }
        while(!q.empty()) {
            auto [dist, r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                auto [dr, dc] = dirs[i];
                int nr = r + dr, nc = c + dc;
                if(isValid(nr, nc, m, n) && rooms[nr][nc] == INF) {
                    rooms[nr][nc] = dist + 1;
                    q.push({dist + 1, nr, nc});
                }
            }
        }
    }
};