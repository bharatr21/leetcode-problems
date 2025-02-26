class Solution {
public:
    int kadane(vector<int>& nums, bool mini) {
        int n = nums.size(), res = nums[0], peak = nums[0];
        for(int i = 1; i < n; i++) {
            if(mini) {
                peak = min(peak + nums[i], nums[i]);
                res = min(peak, res);
            }  else {
                peak = max(peak + nums[i], nums[i]);
                res = max(peak, res);
            }
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0, mn = 1e9 + 1;
        mx = kadane(nums, false);
        mn = kadane(nums, true);
        return max(mx, -mn);
    }
};