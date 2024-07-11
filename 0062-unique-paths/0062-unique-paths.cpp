class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int i, j;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == 0 || j == 0) {grid[i][j] = 1; continue;}
                int down = grid[i-1][j];
                int left = grid[i][j-1];
                grid[i][j] = down + left;
            }
        }
        return grid[m-1][n-1];
    }
};