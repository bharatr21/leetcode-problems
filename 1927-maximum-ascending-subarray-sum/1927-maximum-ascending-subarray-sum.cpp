class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int res = *max_element(nums.begin(), nums.end()), sm = 0;
        for(int i = 0; i < n; i++)
        {
            sm = nums[i];
            for(int j = i + 1; j < n && nums[j] > nums[j - 1]; j++) sm += nums[j];
            res = max(res, sm);
        }
        return res;
    }
};