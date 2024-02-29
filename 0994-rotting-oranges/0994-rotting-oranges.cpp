class Solution {
public:
bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && i < m) && (j >= 0 && j < n);
}
    void bfs(queue<pair<int, pair<int, int>>> &q, vector<vector<int>>& grid, 
    int& oct, int& mx)
    {
        int m = grid.size(), n = grid[0].size();
        while(!q.empty())
        {
            vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            auto [time, coords] = q.front();
            auto [x, y] = coords;
            mx = max(mx, time);
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if(isValid(nx, ny, m, n) && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    q.push({time + 1, {nx, ny}});
                    oct--;
                }
            }
        }

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, oct = 0;
        int mx = 0;
        queue<pair<int, pair<int, int>>> q;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    oct++;
                }
            }
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0, {i, j}});
                }
            }
        }
        if(oct == 0) return 0;
        bfs(q, grid, oct, mx);
        return ((oct <= 0) ? mx: -1);
    }
};