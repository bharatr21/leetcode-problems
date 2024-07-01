class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int st, vector<int>& tmp) {
        int en = nums.size();
        if(st == en) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[st]);
        backtrack(res, nums, st + 1, tmp);
        tmp.pop_back();
        backtrack(res, nums, st + 1, tmp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();
        backtrack(res, nums, 0, tmp);
        return res;
    }
};