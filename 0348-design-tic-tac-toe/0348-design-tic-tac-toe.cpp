class TicTacToe {
public:
    vector<vector<int>> grid;
    TicTacToe(int n) {
        grid.resize(n, vector<int>(n, 0));
    }

    pair<bool, int> winCol(int col, int n, vector<vector<int>>& grid) {
        int flag = true;
        for(int r = 1; r < n; r++) {
            if(grid[r][col] != grid[r-1][col]) {
                flag = false;
                break;
            }
        }
        if(flag) return {true, grid[0][col]};
        else return {false, -1};
    }

    pair<bool, int> winRow(int row, int n, vector<vector<int>>& grid) {
        int flag = true;
        for(int c = 1; c < n; c++) {
            if(grid[row][c] != grid[row][c-1]) {
                flag = false;
                break;
            }
        }
        if(flag) return {true, grid[row][0]};
        else return {false, -1};
    }

    pair<bool, int> winDiag(vector<vector<int>>& grid) {
        int n = grid.size();
        int flag = true;
        for(int i = 1; i < n; i++) {
            if(grid[i][i] != grid[i-1][i-1]) {
                flag = false;
                break;
            }
        }
        if(flag) return {true, grid[0][0]};
        else {
            flag = true;
            for(int i = 1; i < n; i++) {
                if(grid[i][n-i-1] != grid[i-1][n-i]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return {true, grid[0][n-1]};
        else return {false, -1};
    }

    
    int move(int row, int col, int player) {
        int n = grid.size();
        grid[row][col] = player;
        auto [rstatus, rwinner] = winRow(row, n, grid);
        if(rstatus) return rwinner;
        auto [cstatus, cwinner] = winCol(col, n, grid);
        if(cstatus) return cwinner;
        if(row == col || row + col == n - 1) {
            auto [dstatus, dwinner] = winDiag(grid);
            if(dstatus) return dwinner;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */