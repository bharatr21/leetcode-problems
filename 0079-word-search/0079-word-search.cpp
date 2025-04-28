class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return ((x >= 0) && (x < m) && (y >= 0) && (y < n));
    }
    bool backtrack(vector<vector<char>>& board, int x, int y, string word, int idx) {
        if(idx >= word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(!isValid(x, y, m, n) || board[x][y] != word[idx]) return false;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        char tmp = board[x][y];
        board[x][y] = '@';
        for(auto& d: dirs) {
            auto& [dx, dy] = d;
            int nx = x + dx, ny = y + dy;
            if(backtrack(board, nx, ny, word, idx + 1)) return true;
        }
        board[x][y] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        string tmp;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(backtrack(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};