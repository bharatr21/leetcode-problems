class Solution {
public:
    void backtrack(vector<int>& candidates, int start, int end, vector<int>& tmp, vector<vector<int>>& res, int target) {
        if(target < 0) return;
        if(target == 0)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = start; i < end; i++)
        {
            if(i > start && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            backtrack(candidates, i + 1, end, tmp, res, target - candidates[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, n, tmp, res, target);
        return res;
    }
};