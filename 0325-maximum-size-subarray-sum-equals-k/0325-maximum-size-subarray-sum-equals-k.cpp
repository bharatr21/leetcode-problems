class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        vector<long long> pre(n + 1, 0);
        unordered_map<long long, long long> idx;
        idx[pre[0]] = 0;
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + nums[i-1];
            if(!idx.count(pre[i])) idx[pre[i]] = i;
        }
        for(int i = 0; i <= n; i++) {
            if(idx.count(pre[i] - k)) res = max(res, (long long)i - idx[pre[i] - k]);
        }
        return (int)res;
    }
};