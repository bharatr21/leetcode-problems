class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), i; 
        double pre = 1, suf = 1, mx = INT_MIN;
        for(i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            suf = suf * nums[n-1-i];
            pre = pre * nums[i];
            mx = max(mx, max(pre, suf));
        }
        return (int)mx;
    }
};