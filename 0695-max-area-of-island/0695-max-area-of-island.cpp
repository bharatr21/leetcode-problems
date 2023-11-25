class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        return (0 <= i && i < m) && (0 <= j && j < n);
    }

    int bfs(queue<vector<int>>& q, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n)
    {
        int ct = 0, i, j, k;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty())
        {
            vector<int> temp = q.front();
            i = temp[0], j = temp[1];
            q.pop();
            if(isValid(i, j, m, n) && !vis[i][j] && grid[i][j])
            {
                vis[i][j] = 1;
                ct++;
                for(k = 0; k < 4; k++)
                {
                    q.push({i + dirs[k][0], j + dirs[k][1]});
                }
            }
        }
        return ct;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0, ct;
        queue<vector<int>> q;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    q.push({i, j});
                    ct = bfs(q, grid, vis, m, n);
                    ans = max(ans, ct);
                }
            }
        }
        return ans;
    }
};