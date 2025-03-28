class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        int prevMin = -1, prevSecMin = -1, prevMinIdx = -1;
        for(int i = 0; i < k; i++) {
            int cur = costs[0][i];
            if(prevMin == -1 || cur < prevMin) {
                prevSecMin = prevMin;
                prevMinIdx = i;
                prevMin = cur;
            } else if(prevSecMin == -1 || cur < prevSecMin) {
                prevSecMin = cur;
            }
        }
        for(int i = 1; i < n; i++) {
            int mn = -1, secmn = -1, minIdx = -1;
            for(int j = 0; j < k; j++) {
                int cur = costs[i][j];
                if(j == prevMinIdx) {
                    cur += prevSecMin;
                } else {
                    cur += prevMin;
                }
                if(mn == -1 || cur < mn) {
                    secmn = mn;
                    minIdx = j;
                    mn = cur;
                } else if(secmn == -1 || cur < secmn) {
                    secmn = cur;
                }
            }
            prevMin = mn;
            prevSecMin = secmn;
            prevMinIdx = minIdx;
        }
        return prevMin;
    }
};