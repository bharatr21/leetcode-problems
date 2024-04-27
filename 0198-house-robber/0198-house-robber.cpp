class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> res(n, 0);
        if(n <= 1) return nums[n-1];
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for(i = 2; i < n; i++)
        {
            res[i] = max(res[i-1], nums[i] + res[i-2]);
        }
        return max(res[n-1], res[n-2]);
    }
};