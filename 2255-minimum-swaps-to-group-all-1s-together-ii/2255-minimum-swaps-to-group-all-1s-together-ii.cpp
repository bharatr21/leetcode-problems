class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int n = nums.size();
        const int k = accumulate(nums.cbegin(), nums.cend(), 0);
        int window_sum = accumulate(nums.cbegin(), nums.cbegin() + k, 0);
        int swaps = k - window_sum;

        for (int i = 1; i < n; ++i) {
            window_sum += nums[(i - 1 + k) % n] - nums[i - 1];
            swaps = min(swaps, k - window_sum);
        }
        return swaps;
    }
};