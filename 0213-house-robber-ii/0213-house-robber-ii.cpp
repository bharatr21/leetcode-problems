class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i, a, b;
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);
        vector<int> res(n+1, 0);
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n - 1; i++)
        {
            res[i] = max(res[i-1], nums[i] + res[i-2]);
        }
        a = max(res[n-2], res[n-3]);
        res[1] = nums[1];
        res[2] = max(nums[1], nums[2]);
        for(int i = 3; i < n; i++)
        {
            res[i] = max(res[i-1], nums[i] + res[i-2]);
        }
        b = max(res[n-1], res[n-2]);
        return max(a, b);
    }
};