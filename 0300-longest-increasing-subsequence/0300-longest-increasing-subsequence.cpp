class Solution {
public:
    int lis(vector<int>& dp, int idx, vector<int>& nums) {
        if(dp[idx] != -1) return dp[idx];
        int res = 1;
        for(int i = idx - 1; i >= 0; i--) {
            if(nums[i] < nums[idx]) {
                res = max(res, 1 + lis(dp, i, nums));
            }
        }
        cout << endl;
        return (dp[idx] = res);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> dp(n, -1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) lis(dp, i, nums);
        return *max_element(dp.begin(), dp.end());
    }
};