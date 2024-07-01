class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int st, vector<int>& tmp, set<vector<int>>& seen) {
        int en = nums.size();
        if(st == en) {
            if(seen.find(tmp) == seen.end()) {
                res.push_back(tmp);
                seen.insert(tmp);
            }
            return;
        }
        tmp.push_back(nums[st]);
        backtrack(res, nums, st + 1, tmp, seen);
        tmp.pop_back();
        backtrack(res, nums, st + 1, tmp, seen);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        set<vector<int>> seen;
        int n = nums.size();
        backtrack(res, nums, 0, tmp, seen);
        return res;
    }
};