class Solution {
public:
    int uniquePaths(int m, int n) {
        int i, j;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == 0 || j == 0) grid[i][j] = 1;
                else grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};