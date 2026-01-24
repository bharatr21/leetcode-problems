class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = nums[0] + nums[n-1];
        for(int i = 1, j = n-2; i < j; i++, j--) {
            mn = max(mn, nums[i] + nums[j]);
        }
        return mn;
    }
};