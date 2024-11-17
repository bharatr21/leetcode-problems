class Solution {
public:
    int power(vector<int>& nums, int idx, int k) {
        for(int j = idx; j < idx + k - 1; j++) {
            if(nums[j+1] != nums[j] + 1) return -1;
        }
        return nums[idx + k - 1];
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n - k + 1; i++) {
            res.push_back(power(nums, i, k));
        }
        return res;
    }
};