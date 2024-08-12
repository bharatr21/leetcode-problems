class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= target; i++) dp[n][i] = 0;
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int j = 1; j <= target; j++)
            if(nums[idx] <= j) {
                dp[idx][j] = (dp[idx+1][j - nums[idx]] || dp[idx+1][j]);
            }
            else
                dp[idx][j] = dp[idx+1][j];
        }        
        return dp[0][target];
    }
};