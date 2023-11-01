class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), i;
        if(n == 1) return nums[0];
        int sum = nums[0], lmax = nums[0];
        for(i = 1; i < n; i++)
        {
            sum = max(sum + nums[i], nums[i]);
            lmax = max(lmax, sum);
        }
        return lmax;
    }
};