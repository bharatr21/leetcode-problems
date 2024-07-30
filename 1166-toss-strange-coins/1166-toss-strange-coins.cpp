class Solution {
public:
    double probcount(vector<double>& prob, vector<vector<double>>& dp, int pos, int cnt, int target) {
        double res;
        int n = prob.size();
        if(pos == n) return (cnt == target);
        if(dp[pos][cnt] != -1) return dp[pos][cnt];
        res = prob[pos] * probcount(prob, dp, pos+1, cnt+1, target) + (1 - prob[pos]) * probcount(prob, dp, pos+1, cnt, target);
        return (dp[pos][cnt] = res);
    }

    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        if(target > n) return 0;
        vector<double> prev(n+1, -1), cur(n+1, -1);
        int cnt, pos;
        for(cnt = 0; cnt <= n; cnt++) {
            prev[cnt] = ((cnt == target) ? 1 : 0);
        }
        for(pos = n - 1; pos >= 0; pos--) {
            for(cnt = pos; cnt >= 0; cnt--) {
                cur[cnt] = prob[pos] * prev[cnt+1] + (1 - prob[pos]) * prev[cnt];
            }
            prev = cur;
        }
        return prev[0];
    }
};