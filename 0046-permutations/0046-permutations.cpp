class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums) {
        int n = nums.size();
        if(tmp.size() == n) {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(find(tmp.begin(), tmp.end(), nums[i]) == tmp.end()) {
                tmp.push_back(nums[i]);
                backtrack(res, tmp, nums);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums);
        return res;
    }
};