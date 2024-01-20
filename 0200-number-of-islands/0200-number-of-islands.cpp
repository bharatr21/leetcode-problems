class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c)
    {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int i;
        for(i = 0; i < 4; i++)
        {
            int dx = dirs[i][0], dy = dirs[i][1];
            int nr = r + dx, nc = c + dy;
            if(isValid(grid, nr, nc) && grid[nr][nc] == '1' && !vis[nr][nc])
            {
                vis[nr][nc] = 1;
                dfs(grid, vis, nr, nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ct = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    vis[i][j] = 1;
                    ct++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return ct;
    }
};