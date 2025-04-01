class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<pair<int, int>> qinfo;
        for(vector<int> q: questions) qinfo.push_back({q[0], q[1]});
        int n = qinfo.size();
        vector<long> dp(n, -1);
        dp[n-1] = qinfo[n-1].first;
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i+1];
            if(i + qinfo[i].second + 1 < n) {
                dp[i] = max(dp[i], qinfo[i].first + dp[i + qinfo[i].second + 1]);
            } else {
                dp[i] = max(dp[i], 1L * qinfo[i].first);
            }
        }
        return dp[0];
    }
};