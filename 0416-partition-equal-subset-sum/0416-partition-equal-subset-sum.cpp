class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int tgt = sum / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(tgt + 1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        for(int i = 1; i <= tgt; i++) dp[n-1][i] = false;
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 1; j <= tgt; j++) 
            {
                dp[i][j] = dp[i][j] | dp[i+1][j];
                if(nums[i+1] <= j) dp[i][j] = dp[i][j] | dp[i+1][j - nums[i+1]];
            }
        }
        return dp[0][tgt];
    }
};