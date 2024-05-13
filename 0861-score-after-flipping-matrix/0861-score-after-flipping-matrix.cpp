class Solution {
public:
    void flipRow(vector<vector<int>>& grid, int r, int c) {
        int n = grid[0].size(), j;
        for(j = 0; j < n; j++) {
            grid[r][j] = 1 - grid[r][j];
        }
    }

    void flipCol(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), i;
        for(i = 0; i < m; i++) {
            grid[i][c] = 1 - grid[i][c];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        int res = 0;
        for(i = 0; i < m; i++)
        {
                if(grid[i][0] == 0)
                {
                    flipRow(grid, i, j);
                }
        }
        for(j = 0; j < n; j++)
        {
            int cnto = 0, cntz = 0;
            for(i = 0; i < m; i++)
            {
                if(grid[i][j] == 0) cntz++;
                else cnto++;
            }
            if(cntz > cnto) flipCol(grid, i, j);
        }
        for(j = 0; j < n; j++)
        {
            for(i = 0; i < m; i++)
            {
                res += grid[i][j] * (1 << (n - j - 1)); 
            }
        }
        return res;
    }
};