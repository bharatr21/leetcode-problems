class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        vector<pair<int, int>> chosen;
        if(n <= 2) return *max_element(nums.begin(), nums.end());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            if(dp[i-2] + nums[i] > dp[i-1]) {
                dp[i] = dp[i-2] + nums[i];
            } else {
                dp[i] = dp[i-1];
            }
        }
        bool skip = false;
        for(int i = n - 1; i >= 2; i--) {
            if(skip) skip = false;
            else if(dp[i-2] + nums[i] > dp[i-1]) {
                chosen.push_back({i, nums[i]});
                skip = true;
            }
        }
        if(skip) chosen.push_back({0, nums[0]});
        else chosen.push_back({1, nums[1]});
        for(auto el: chosen) cout << "(" << el.first << ", " << el.second << ")" << endl;
        return dp[n-1];
    }
};