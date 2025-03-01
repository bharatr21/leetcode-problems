class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) res.push_back(nums[i]);
        }
        int k = res.size();
        for(int i = k; i < n; i++) res.push_back(0);
        return res;
    }
};