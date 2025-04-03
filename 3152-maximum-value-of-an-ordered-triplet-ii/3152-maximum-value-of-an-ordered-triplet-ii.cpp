class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), suf(n, 0);
        long long mx = 0;
        pre[0] = nums[0], suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i-1], nums[i]);
        }
        for(int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i+1], nums[i]);
        }
        for(int j = 1; j < n - 1; j++) {
            mx = max(mx, 1LL * (pre[j - 1] - nums[j]) * suf[j + 1]);
        }
        return mx;
    }
};