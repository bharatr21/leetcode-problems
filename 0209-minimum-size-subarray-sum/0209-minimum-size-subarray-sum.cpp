class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int st = 0, en = 0, csum = 0, mn = n + 1;
        while(en < n) {
            csum += nums[en];
            while(csum >= target) {
                mn = min(mn, en - st + 1);
                csum -= nums[st];
                st++;
            }
            en++;
        }
        return (mn > n) ? 0 : mn;
    }
};