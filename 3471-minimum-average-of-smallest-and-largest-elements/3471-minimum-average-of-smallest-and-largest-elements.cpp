class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i, j;
        double res = nums[n - 1];
        for(i = 0, j = n - 1; i < n/2; i++, j--) {
            res = min(res, 0.5 * (nums[i] + nums[j]));
        }
        return res;
    }
};