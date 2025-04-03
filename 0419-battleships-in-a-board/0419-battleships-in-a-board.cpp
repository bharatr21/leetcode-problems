class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    void dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& board, int m, int n) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vis[x][y] = true;
        for(auto& d: dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            if(isValid(nx, ny, m, n) && !vis[nx][ny] && board[nx][ny] == 'X') {
                dfs(nx, ny, vis, board, m, n);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ct = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && board[i][j] == 'X') {
                    ct++;
                    dfs(i, j, vis, board, m, n);
                }
            }
        }
        return ct;
    }
};