class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, ct = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                ct++;
                res = max(res, ct);
            } else {
                ct = 0;
            }
        }
        return res;
    }
};