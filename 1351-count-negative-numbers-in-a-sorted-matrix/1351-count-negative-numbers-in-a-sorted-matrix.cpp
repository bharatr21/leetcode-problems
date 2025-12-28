class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ct = 0, m = grid.size(), n = grid[0].size();
        int curidx = n - 1;
        for(auto &row: grid) {
            while(curidx >= 0 && row[curidx] < 0) curidx--;
            ct += (n - (curidx + 1));
        }
        return ct;
    }
};