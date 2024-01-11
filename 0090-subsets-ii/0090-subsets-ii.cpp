class Solution {
public:
    void backtrack(vector<int>& nums, int start, int end, vector<int>& temp, vector<vector<int>>& res) {
        if(start >= end)
        {
            if(find(res.begin(), res.end(), temp) == res.end())
                res.push_back(temp);
            return;
        }
        temp.push_back(nums[start]);
        backtrack(nums, start + 1, end, temp, res);
        temp.pop_back();
        backtrack(nums, start + 1, end, temp, res);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, n, temp, res);
        return res;
    }
};