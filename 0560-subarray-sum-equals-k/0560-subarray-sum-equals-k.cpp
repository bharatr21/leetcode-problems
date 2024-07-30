class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), i, j, res = 0;
        vector<int> pre(n+1, 0);
        for(i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(i = n; i >= 0; i--) {
            for(j = i - 1; j >= 0; j--) {
                if(pre[i] - pre[j] == k) res++;
            }
        }
        return res;
    }
};