class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return {-1, -1};
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        if(lb == nums.end() || *lb != target || *prev(ub) != target) return {-1, -1};
        else return {(int)(lb - nums.begin()), (int)(prev(ub) - nums.begin())};
    }
};