class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for(int i = 0; i < n - 1; i++) {
            mx = max(mx, abs(nums[i+1] - nums[i]));
        }
        mx = max(mx, abs(nums[0] - nums[n-1]));
        return mx;
    }
};