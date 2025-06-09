class Solution {
public:
    bool isValid(int x, int y, int m, int n) {return (x >= 0 && x < m && y >= 0 && y < n);}
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, rot = 0;
        // vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0, 1},{0, -1}, {1, 0},{-1, 0}};
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        if(!fresh) return 0;
        int mx = 0;
        while(fresh > 0 && !q.empty()) {
            auto [r, c, time] = q.front();
            q.pop();
            mx = max(mx, time);
            for(int i = 0; i < 4; i++) {
                auto [dr, dc] = dirs[i];
                int nr = r + dr, nc = c + dc;
                if(isValid(nr, nc, m, n) && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc, time + 1});
                }
            }
        }
        while(!q.empty()) {
            auto [r, c, time] = q.front();
            mx = max(mx, time);
            q.pop();
        }
        return ((fresh) ? -1: mx);
    }
};