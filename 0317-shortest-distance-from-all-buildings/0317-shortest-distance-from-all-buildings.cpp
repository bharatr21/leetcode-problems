class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> srcs;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<int> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    srcs.push_back({i, j});
                    q.push(srcs.size() - 1);
                }
            }
        }
        vector<vector<int>> distances(m, vector<int>(n, 0));
        while(!q.empty()) {
            auto idx = q.front();
            auto src = srcs[idx];
            q.pop();
            queue<tuple<int, int, int>> bfsq;
            bfsq.push({src.first, src.second, 0});
            vector<vector<int>> localDist(m, vector<int>(n, 1e5));
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            while(!bfsq.empty())
            {
                auto [x, y, dist] = bfsq.front();
                bfsq.pop();
                for(auto v: dirs)
                {
                    int nx = x + v.first;
                    int ny = y + v.second;
                    if(isValid(nx, ny, m, n) && !vis[nx][ny] && grid[nx][ny] == 0)
                    {
                        vis[nx][ny] = true;
                        localDist[nx][ny] = dist + 1;
                        bfsq.push({nx, ny, dist + 1});
                    }
                }
            }
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(localDist[i][j] >= 1e5) distances[i][j] = 1e5;
                    else distances[i][j] += localDist[i][j];
                }
            }
        }
        int mn = 1e5;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(distances[i][j] != 0) mn = min(mn, distances[i][j]);
            } 
        }
        return ((mn >= 1e5) ? -1 : mn);
    }
};