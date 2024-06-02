class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], sum = nums[0], i;
        for(i = 1; i < n; i++)
        {
            mx = max(mx + nums[i], nums[i]);
            sum = max(mx, sum);
        }
        return sum;
    }
};