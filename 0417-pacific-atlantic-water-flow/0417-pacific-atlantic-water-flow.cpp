class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (0 <= i && i < m) && (0 <= j && j < n);
    }
    void reachable(queue<pair<int, int>> &q, vector<vector<int>>& vis, 
    vector<vector<int>>& heights) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = heights.size(), n = heights[0].size();
        while(!q.empty())
        {
            auto [x, y] = q.front();
            // cout << "(" << x << ", " << y << ")";
            // cout << "(" << heights[x][y] << ", " << y << ")";
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if(isValid(nx, ny, m, n) && !vis[nx][ny] && (heights[nx][ny] >= heights[x][y]))
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(), i, j;
        vector<vector<int>> pvis(m, vector<int>(n, 0));
        vector<vector<int>> avis(m, vector<int>(n, 0));
        vector<vector<int>> res;
        queue<pair<int, int>> pq, aq;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                {
                    pq.push({i, j});
                    pvis[i][j] = 1;
                }
                if(i == m - 1 || j == n - 1)
                {
                    aq.push({i, j});
                    avis[i][j] = 1;
                }
            }
        }
        reachable(pq, pvis, heights);
        reachable(aq, avis, heights);
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(pvis[i][j] && avis[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};