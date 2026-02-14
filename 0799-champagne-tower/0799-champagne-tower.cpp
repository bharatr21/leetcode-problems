class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0;
        vector<double> res(102, 0.0);
        res[0] = poured * 1.0;
        for(int r = 0; r < query_row; r++) {
            for(int c = r; c >= 0; c--) {
                if(res[c] > 1) {
                    double q = (res[c] - 1.0) / 2.0;
                    res[c+1] += q;
                    res[c] = q;
                } else {
                    res[c] = 0;
                }
            }
        }
        return min(1.0, res[query_glass]);
    }
};