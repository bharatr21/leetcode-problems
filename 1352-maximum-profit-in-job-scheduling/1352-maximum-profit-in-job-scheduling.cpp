class Solution {
public:
    int solve(int idx, int n, vector<vector<int>>& info, vector<int>& startTime, vector<int>& dp) {
        if(idx >= n) return 0;
        if(idx == n-1) return (dp[n-1] = info[n-1][2]);
        if(dp[idx] != -1) return dp[idx];
        int res = 0;
        int nextIdx = lower_bound(startTime.begin(), startTime.end(), info[idx][1]) - startTime.begin();
        res = max(res, solve(idx + 1, n, info, startTime, dp));
        res = max(res, info[idx][2] + solve(nextIdx, n, info, startTime, dp));
        return (dp[idx] = res);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> info;
        int n = startTime.size();
        for(int i = 0; i < n; i++) {
            info.push_back({startTime[i], endTime[i], profit[i]});
        }
        vector<int> dp(n + 1, -1);
        sort(startTime.begin(), startTime.end());
        sort(info.begin(), info.end());
        solve(0, n, info, startTime, dp);
        return dp[0];
    }
};