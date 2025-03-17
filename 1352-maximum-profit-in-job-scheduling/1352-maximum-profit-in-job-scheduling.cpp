class Solution {
public:
    int getMaxProfit(int idx, vector<vector<int>>& jobs, vector<int>& start, vector<int>& dp) {
        int maxProfit = 0;
        int n = start.size();
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int nextIdx = lower_bound(start.begin(), start.end(), jobs[idx][1]) - start.begin();
        maxProfit = max(getMaxProfit(idx + 1, jobs, start, dp),
        jobs[idx][2] + getMaxProfit(nextIdx, jobs, start, dp));
        return (dp[idx] = maxProfit);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        vector<int> sortedStart = startTime;
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(sortedStart.begin(), sortedStart.end());
        vector<int> dp(n+1, -1);
        getMaxProfit(0, jobs, sortedStart, dp);
        return dp[0];
    }
};