class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        int n = nums.size();
        auto [first, last] = equal_range(nums.begin(), nums.end(), 0);
        return max(first - nums.begin(), nums.end() - last);
    }
};