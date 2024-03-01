class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
    int INF = 2147483647;
    void bfs(queue<pair<int, int>> &q, vector<vector<int>>& rooms)
    {
        int m = rooms.size(), n = rooms[0].size();
        while(!q.empty())
        {
            vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                while(isValid(nx, ny, m, n) && rooms[nx][ny] == INF)
                {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size(), i, j;
        queue<pair<int, int>> q;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(rooms[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        bfs(q, rooms);
    }
};