class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int idx, int target, int sum) {
        int n = nums.size();
        int modtarget = target + sum;
        if(target > sum || target < -sum) return 0;
        else if(idx == n) {
            return ((target == 0) ? 1 : 0);
        }
        if(dp[idx][modtarget] != -1) return dp[idx][modtarget];
        int sub = solve(dp, nums, idx+1, target + nums[idx], sum);
        int add = solve(dp, nums, idx+1, target - nums[idx], sum);
        return (dp[idx][modtarget] = sub + add);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2*sum+1, -1));
        return solve(dp, nums, 0, target, sum);
    }
};