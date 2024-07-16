class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), i;
        if(n == 0) return 0;
        double cur = 1, mx_so_far = nums[0], mn_so_far = nums[0], res = mx_so_far;
        for(i = 1; i < n; i++) {
            cur = nums[i];
            double mx = max(cur, max(mx_so_far * cur, mn_so_far * cur));
            mn_so_far = min(cur, min(mx_so_far * cur, mn_so_far * cur));
            mx_so_far = mx;
            res =  max(mx_so_far, res);
        }
        return (int)res;
    }
};