class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int sz = nums.size(), patches = 0, i = 0;
        long miss = 1;
        while(miss <= n) {
            if(i < sz && nums[i] <= miss) {miss += nums[i]; i++;}
            else
            {
                miss = miss * 2;
                patches++;
            }
        }
        return patches;
    }
};