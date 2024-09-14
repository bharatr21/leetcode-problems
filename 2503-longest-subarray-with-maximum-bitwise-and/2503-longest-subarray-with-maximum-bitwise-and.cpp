class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0, mx = 0, el = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] == el) {
                res++;
                mx = max(mx, res);
            }
            else res = 0;
        }
        return mx;
    }
};