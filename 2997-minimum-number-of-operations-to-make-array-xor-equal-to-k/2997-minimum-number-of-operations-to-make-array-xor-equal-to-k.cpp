class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int curXor = 0;
        for(int n: nums) curXor ^= n;
        return __builtin_popcount(curXor^k);
    }
};