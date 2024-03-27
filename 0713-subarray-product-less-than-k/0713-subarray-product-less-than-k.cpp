class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        int n = nums.size();
        int st = 0, en = 0, res = 0;
        while(prod < k && en < n)
        {
            prod *= nums[en];
            while(prod >= k && st < n)
            {
                prod /= nums[st++];
            }
            res += (en - st + 1);
            en++;
        }
        return res;
    }
};
