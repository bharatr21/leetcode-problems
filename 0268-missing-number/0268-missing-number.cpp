class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            res ^= (i ^ nums[i]);
        }
        res ^= n;
        return res;
    }
};