class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rowFlips = 0, colFlips = 0;
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n/2; c++) 
            {
                if(grid[r][c] != grid[r][n-c-1]) colFlips++;
            }
        }

        for(int r = 0; r < m/2; r++)
        {
            for(int c = 0; c < n; c++) 
            {
                if(grid[r][c] != grid[m-r-1][c]) rowFlips++;
            }
        }
        return min(rowFlips, colFlips);
    }
};