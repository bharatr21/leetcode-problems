class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size(), i;
        for(i = 1; i < n; i++) {
            if(!((nums[i-1] & 1) ^ (nums[i] & 1))) return false;
        }
        return true;
    }
};