class Solution {
public:
    bool isValid(int i, int j, vector<vector<bool>>& vis)
    {
        int m = vis.size(), n = vis[0].size();
        return ((i >=0 && i < m) && (j >= 0 && j < n));
    }
    void dfs(vector<vector<bool>>& vis, vector<vector<char>>& grid, int i, int j) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int k;
        if(isValid(i, j, vis) && !vis[i][j] && grid[i][j] == '1')
        {
            vis[i][j] = true;
            for(k = 0; k < 4; k++)
            {
                int dx = dirs[k][0];
                int dy = dirs[k][1];
                dfs(vis, grid, i + dx, j + dy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        int ct = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    ct++;
                    dfs(vis, grid, i, j);
                }                
            }
        }
        return ct;
    }
};