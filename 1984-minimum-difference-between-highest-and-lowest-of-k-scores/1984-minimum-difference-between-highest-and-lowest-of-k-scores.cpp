class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), mn = 100001;
        sort(nums.begin(), nums.end());
        for(int i = 0; i + k - 1 < n; i++) {
            mn = min(mn, nums[i+k-1] - nums[i]);
        }
        return mn;
    }
};