class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& tmp, set<vector<int>>& seen, vector<int>& nums) {
        int n = nums.size();
        if(tmp.size() == n) {
            vector<int> v;
            for(int el: tmp) v.push_back(nums[el]);
            if(seen.find(v) == seen.end()) {
                res.push_back(v);
                seen.insert(v);
            }
            return;
        }

        for(int i = 0; i < n; i++) {
            if(find(tmp.begin(), tmp.end(), i) == tmp.end()) {
                tmp.push_back(i);
                backtrack(res, tmp, seen, nums);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        set<vector<int>> seen;
        backtrack(res, tmp, seen, nums);
        return res;
    }
};