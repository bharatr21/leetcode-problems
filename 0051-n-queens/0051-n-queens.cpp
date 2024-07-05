class Solution {
public:
    void backtrack(vector<vector<string>>& res, vector<vector<char>>& board, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antidiags, int row, int n) {
        vector<string> tmp;
        if(row == n) {
            for(vector<char> v: board) {
                string stmp(v.begin(), v.end());
                tmp.push_back(stmp);
            }
            res.push_back(tmp);
            return;
        }
        for(int col = 0; col < n; col++) {
            int diag = row + col;
            int antidiag = row - col;
            if(cols.count(col) || diags.count(diag) || antidiags.count(antidiag)) continue;
            cols.insert(col);
            diags.insert(diag);
            antidiags.insert(antidiag);
            board[row][col] = 'Q';
            backtrack(res, board, cols, diags, antidiags, row + 1, n);
            cols.erase(col);
            diags.erase(diag);
            antidiags.erase(antidiag);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> res;
        unordered_set<int> cols, diags, antidiags;
        backtrack(res, board, cols, diags, antidiags, 0, n);
        return res;
    }
};