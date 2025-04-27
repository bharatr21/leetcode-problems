class Solution {
public:
    bool validateRow(int idx, vector<vector<char>>& board) {
        unordered_set<char> seen;
        for(int i = 0; i < 9; i++) {
            if(board[i][idx] != '.') {
                if(seen.count(board[i][idx])) return false;
                seen.insert(board[i][idx]);
            }
        }
        return true;
    }

    bool validateCol(int idx, vector<vector<char>>& board) {
        unordered_set<char> seen;
        for(int j = 0; j < 9; j++) {
            if(board[idx][j] != '.') {
                if(seen.count(board[idx][j])) return false;
                seen.insert(board[idx][j]);
            }
        }
        return true;
    }

    bool validateBox(int i, int j, vector<vector<char>>& board) {
        unordered_set<char> seen;
        for(int roff = 0; roff < 3; roff++) {
            for(int coff = 0; coff < 3; coff++) {
                if(board[i * 3 + roff][j * 3 + coff] != '.') {
                    if(seen.count(board[i * 3 + roff][j * 3 + coff])) return false;
                    seen.insert(board[i * 3 + roff][j * 3 + coff]);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int j = 0; j < 9; j++) {
            if(!validateRow(j, board)) return false;
        }
        for(int i = 0; i < 9; i++) {
            if(!validateCol(i, board)) return false;
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!validateBox(i, j, board)) return false;
            }
        }
        return true;
    }
};