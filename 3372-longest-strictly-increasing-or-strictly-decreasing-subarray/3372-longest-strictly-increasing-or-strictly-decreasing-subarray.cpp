class Solution {
public:
    bool isMonotonic(vector<int>& nums, int st, int en) {
        bool inc = false, dec = false;
        if(en == st) return 1;
        if(en >= st + 1) {
            if(nums[st+1] > nums[st]) inc = true;
            else if(nums[st+1] < nums[st]) dec = true;
            else return false;
        }
        for(int i = st+1; i < en; i++) {
            if((dec && (nums[i] <= nums[i+1])) || (inc && (nums[i] >= nums[i+1]))) return false;
        }
        return true;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= i; j--) {
                if(isMonotonic(nums, i, j)) {
                    mx = max(mx, j - i + 1);
                }
            }
        }
        return mx;
    }
};