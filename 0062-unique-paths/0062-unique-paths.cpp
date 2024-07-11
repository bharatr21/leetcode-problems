class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if(i == 0 || j == 0) return 1;
        else if(grid[i][j] != 0) return grid[i][j];
        else {
            int down = solve(grid, i-1, j);
            int left = solve(grid, i, j-1);
            return (grid[i][j] = down + left);
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        return solve(grid, m-1, n-1);
    }
};