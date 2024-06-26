class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        int minx = m, miny = n, maxx = -1, maxy = -1;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(grid[i][j]) {
                    minx = min(minx, i);
                    miny = min(miny, j);
                    maxx = max(maxx, i);
                    maxy = max(maxy, j);
                }
            }
        }
        return ((maxx - minx + 1) * (maxy - miny + 1));
    }
};