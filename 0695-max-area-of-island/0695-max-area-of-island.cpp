class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        return (0 <= i && i < m) && (0 <= j && j < n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        int mx = 0, ct = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    q.push({i, j});
                    ct = 0;
                    while(!q.empty())
                    {
                        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                        auto [x, y] = q.front();
                        q.pop();    
                        if(isValid(x, y, m, n) && !vis[x][y] && grid[x][y] == 1)
                        {
                            ct++;
                            vis[x][y] = 1;
                            for(int k = 0; k < 4; k++)
                            {
                                q.push({x + dirs[k][0], y + dirs[k][1]});
                            }
                        }
                    }
                    mx = max(mx, ct);
                }
            }
        }
        return mx;       
    }
};