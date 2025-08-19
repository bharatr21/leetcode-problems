class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        int m = matrix.size(), n = matrix[0].size(), res;
        if(row == m - 1) return (dp[row][col] = matrix[row][col]);
        if(dp[row][col] != -10001) return dp[row][col];
        else {
            res = matrix[row][col] + solve(matrix, row + 1, col, dp);
            if(col > 0) res = min(res, matrix[row][col] + solve(matrix, row + 1, col - 1, dp));
            if(col < n - 1) res = min(res, matrix[row][col] + solve(matrix, row + 1, col + 1, dp));
        }
        return (dp[row][col] = res);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -10001));
        int res = 10001;
        for(int col = 0; col < n; col++) {
            res = min(res, solve(matrix, 0, col, dp));
        }
        return res;
    }
};