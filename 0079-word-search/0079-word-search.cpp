class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    bool solve(vector<vector<char>>& board, int r, int c, int idx, string word)
    {
        if(idx == word.size())
        {
            return true;
        }
        if(!isValid(board, r, c) || board[r][c] != word[idx]) return false;
        board[r][c] = '1';
        bool flag = solve(board, r+1, c, idx+1, word) ||
        solve(board, r-1, c, idx+1, word) ||
        solve(board, r, c+1, idx+1, word) ||
        solve(board, r, c-1, idx+1, word);
        board[r][c] = word[idx];
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        string tmp;
        int m = board.size(), n = board[0].size(), i, j;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {

                if(board[i][j] == word[0] && solve(board, i, j, 0, word)) return true;   
            }
        }
        return false;
    }
};