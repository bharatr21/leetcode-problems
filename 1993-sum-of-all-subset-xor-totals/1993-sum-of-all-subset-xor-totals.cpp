class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int mask = 0; mask <= (1 << n); mask++) {
            int tmp = mask;
            int subsetXor = 0;
            for(int i = 0; i < n; i++) {
                if(tmp & (1 << i)) subsetXor ^= nums[i];
            }
            res += subsetXor;
        }
        return res;
    }
};