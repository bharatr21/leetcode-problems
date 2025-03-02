class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 8e6 + 1), cur(n, 8e6 + 1);
        prev[0] = grid[0][0];
        for(int j = 1; j < n; j++) prev[j] = prev[j-1] + grid[0][j];
        for(int i = 1; i < m; i++) {
            cur[0] = prev[0] + grid[i][0];
            for(int j = 1; j < n; j++) {
                cur[j] = grid[i][j] + min(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return prev[n-1];
    }
};