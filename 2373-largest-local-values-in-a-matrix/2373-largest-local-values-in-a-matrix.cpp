class Solution {
public:
    int findLocal(vector<vector<int>>& grid, int row, int col) {
        int mx = 0, i, j;
        for(i = row; i < row + 3; i++)
        {
            for(j = col; j < col + 3; j++)
            {
               mx = max(mx, grid[i][j]);
            }
        }
        return mx;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(), i, j;
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for(i = 0; i < n - 2; i++)
        {
            for(j = 0; j < n - 2; j++)
            {
                res[i][j] = findLocal(grid, i, j);
            }
        }
        return res;
    }
};