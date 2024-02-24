class Solution {
public:
    bool isCorner(int i, int j, int m, int n) {
        return (i == 0 || i == m - 1 || j == 0 || j == n - 1);
    }
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& nflip)
    {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = board.size(), n = board[0].size();
        for(int k = 0; k < 4; k++)
        {
            int nx = x + dirs[k][0];
            int ny = y + dirs[k][1];
            if(isValid(nx, ny, m, n) && !nflip[nx][ny] && board[nx][ny] == 'O')
            {
                nflip[nx][ny] = 1;
                dfs(nx, ny, board, nflip);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), i, j;
        vector<vector<int>> nflip(m, vector<int>(n, 0));
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(isCorner(i, j, m, n) && !nflip[i][j] && board[i][j] == 'O')
                {
                    nflip[i][j] = 1;
                    dfs(i, j, board, nflip);
                }
            }
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(!nflip[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};