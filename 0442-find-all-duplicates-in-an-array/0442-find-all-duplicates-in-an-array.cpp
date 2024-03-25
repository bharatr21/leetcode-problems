class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int n: nums)
        {
            if(nums[abs(n) - 1] < 0) ans.push_back(abs(n));
            nums[abs(n) - 1] = -nums[abs(n) - 1];
        }
        return ans;
    }
};