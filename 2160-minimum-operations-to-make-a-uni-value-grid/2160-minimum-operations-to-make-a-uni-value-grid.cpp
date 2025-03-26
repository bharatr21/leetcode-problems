class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = -1, res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> flatgrid;
        for(auto& row: grid) {
            for(auto& el: row) {
                flatgrid.push_back(el);
            }
        }
        for(auto& el: flatgrid) {
            if(rem != -1 && rem != el % x) return -1;
            rem = el % x;
        }
        sort(flatgrid.begin(), flatgrid.end());
        if((m * n) % 2 == 0) {
            int med = flatgrid[(m * n) / 2];
            int ops = 0;
            for(int el: flatgrid) ops += (abs(el - med) / x);
            res = ops;
            med = flatgrid[(m * n) / 2 - 1];
            ops = 0;
            for(int el: flatgrid) ops += (abs(el - med) / x);
            res = min(res, ops);
        }
        else {
            int med = flatgrid[(m * n) / 2];
            int ops = 0;
            for(int el: flatgrid) ops += (abs(el - med) / x);
            res = ops;
        }
        return res;
    }
};