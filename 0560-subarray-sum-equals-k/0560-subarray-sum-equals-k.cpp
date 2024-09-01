class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> pre(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j <= n; j++) {
                if(pre[j] - pre[i] == k) res++;
            }
        }
        return res;
    }
};