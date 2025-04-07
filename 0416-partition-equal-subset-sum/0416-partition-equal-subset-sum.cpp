class Solution {
public:
    bool subset(int idx, int tgt, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(tgt == 0) return true;
        else if(idx == n || tgt < 0) return false;
        else if(dp[idx][tgt] != -1) return dp[idx][tgt];
        bool pick = subset(idx + 1, tgt - nums[idx], nums, dp);
        bool notPick = subset(idx + 1, tgt, nums, dp);
        return dp[idx][tgt] = (pick || notPick);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int tgt = sum / 2, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return subset(0, tgt, nums, dp);
    }
};