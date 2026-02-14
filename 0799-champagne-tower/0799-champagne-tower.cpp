class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> res(102, vector<double>(102, 0.0));
        res[0][0] = poured * 1.0;
        for(int r = 0; r <= query_row; r++) {
            for(int c = 0; c <= r; c++) {
                double q = (res[r][c] - 1.0) / 2.0;
                if(q > 0) {
                    res[r+1][c] += q;
                    res[r+1][c+1] += q;
                }
            }
        }
        return min(1.0, res[query_row][query_glass]);
    }
};