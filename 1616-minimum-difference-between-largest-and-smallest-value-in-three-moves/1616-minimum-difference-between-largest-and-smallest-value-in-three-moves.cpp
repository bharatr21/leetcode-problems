class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), i, j;
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int mind = INT_MAX;
        for(i = 0, j = n - 4; i < 4; i++, j++) {
            mind = min(mind, nums[j] - nums[i]);
        }
        return mind;
    }
};