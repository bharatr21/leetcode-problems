class Solution {
public:
    bool canFind(vector<vector<int>>& dp, vector<int>& nums, int idx, int target) {
        int n = nums.size();
        if(target == 0) return true;
        else if(target < 0 || idx >= n) return false;
        else if(dp[idx][target] != -1) return dp[idx][target];
        bool pick = canFind(dp, nums, idx + 1, target - nums[idx]);
        bool notPick = canFind(dp, nums, idx + 1, target);
        return (dp[idx][target] = (pick || notPick));
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return canFind(dp, nums, 0, target);
    }
};