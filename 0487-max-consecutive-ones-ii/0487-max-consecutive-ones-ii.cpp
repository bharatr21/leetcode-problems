class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int st = 0, en = 0, numZeros = 0, mx = 0;
        while(en < n) {
            if(nums[en] == 0) numZeros++;
            while(numZeros >= 2) {
                if(nums[st] == 0) numZeros--;
                st++;
            }
            if(en < n) mx = max(mx, en - st + 1);
            en++;
        }
        return mx;
    }
};