class Solution {
public:
    void backtrack(vector<int>& nums, int start, int end, vector<int>& temp, vector<vector<int>>& res) {
        if (start == end) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[start]);
        backtrack(nums, start + 1, end, temp, res);
        temp.pop_back();
        backtrack(nums, start + 1, end, temp, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), i, j;
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, 0, n, temp, res);
        return res;
    }
};