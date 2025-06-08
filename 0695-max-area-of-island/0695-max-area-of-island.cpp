class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();
        int sz = 1;
        vis[x][y] = true;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < 4; i++) {
            auto [dx, dy] = dirs[i];
            int nx = x + dx, ny = y + dy;
            if(isValid(nx, ny, m, n) && grid[nx][ny] && !vis[nx][ny]) sz += dfs(nx, ny, grid, vis);
        }
        return sz;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    res = max(res, dfs(i, j, grid, vis));
                }
            }
        }
        return res;
    }
};