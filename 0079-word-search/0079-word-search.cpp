class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n); 
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int idx) {
        if(idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(!isValid(r, c, m, n) || board[r][c] != word[idx]) return false;
        bool flag = false, up, down, left, right;
        board[r][c] = '@';
        up = backtrack(board, word, r-1, c, idx + 1);
        down = backtrack(board, word, r+1, c, idx + 1);
        left = backtrack(board, word, r, c-1, idx + 1);
        right = backtrack(board, word, r, c+1, idx + 1);
        flag = (left || right || up || down);
        board[r][c] = word[idx]; // Backtracking step
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), i, j;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    if(backtrack(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};