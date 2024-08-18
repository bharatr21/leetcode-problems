class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] == 1) {
                dp[i] = dp[i-1] + 1;
            }
            else dp[i] = 1;
        }
        vector<int> res;
        for(int i = k - 1; i < n; i++) {
            if(dp[i] >= k) res.push_back(nums[i]);
            else res.push_back(-1);
        }
        return res;
    }
};