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
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        int cnt, pos;
        for(cnt = 0; cnt <= n; cnt++) {
            dp[n][cnt] = ((cnt == target) ? 1 : 0);
        }
        for(pos = n - 1; pos >= 0; pos--) {
            for(cnt = pos; cnt >= 0; cnt--) {
                dp[pos][cnt] = prob[pos] * dp[pos+1][cnt+1] + (1 - prob[pos]) * dp[pos+1][cnt];
            }
        }
        return dp[0][0];
    }
};