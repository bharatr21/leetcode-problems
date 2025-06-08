class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[x][y] = true;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < 4; i++) {
            auto [dx, dy] = dirs[i];
            int nx = x + dx; 
            int ny = y + dy;
            if(isValid(nx, ny, m, n) && !vis[nx][ny] && grid[nx][ny] == '1') {
                dfs(nx, ny, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    res++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return res;
    }
};