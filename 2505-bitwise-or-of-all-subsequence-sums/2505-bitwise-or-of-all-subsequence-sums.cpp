class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long res = 0;
        int n = nums.size(), i;
        long long pre = 0;
        res |= nums[0];
        for(i = 0; i < n; i++)
        {
            pre += nums[i];
            res |= (nums[i] | pre);
        }
        return res;
    }
};