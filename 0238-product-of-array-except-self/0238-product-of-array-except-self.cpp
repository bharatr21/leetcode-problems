class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), i;
        vector<int> pre(n, 1), suf(n, 1);
        for(i = 1; i < n; i++)
        {
            pre[i] = pre[i-1] * nums[i-1];
        }
        for(i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i+1] * nums[i+1];
        }
        for(i = 0; i < n; i++)
        {
            res.push_back(pre[i] * suf[i]);
        }
        return res;
    }
};