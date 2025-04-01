class Solution {
public:
    long solve(int idx, vector<pair<int, int>>& qinfo, vector<long>& dp) {
        int n = qinfo.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        long pick = qinfo[idx].first + solve(idx + qinfo[idx].second + 1, qinfo, dp);
        long notPick = solve(idx + 1, qinfo, dp);
        return (dp[idx] = max(pick, notPick));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<pair<int, int>> qinfo;
        for(vector<int> q: questions) {
            qinfo.push_back({q[0], q[1]});
        }
        int n = qinfo.size();
        vector<long> dp(n+1, -1);
        dp[n-1] = qinfo[n-1].first;
        solve(0, qinfo, dp);
        return dp[0];
    }
};