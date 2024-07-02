class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, 
    vector<int>& tmp, int idx, int target) {
        int n = candidates.size();
        if(target == 0) {
            res.push_back(tmp);
            return;
        }
        else if(target < 0) return;
        for(int i = idx; i < n; i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            backtrack(res, candidates, tmp, i + 1, target - candidates[i]);
            tmp.pop_back(); //backtracking step
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        map<int, int> ctr;
        for(int el: candidates) ctr[el]++;
        vector<pair<int, int>> counter(ctr.begin(), ctr.end());
        backtrack(res, candidates, tmp, 0, target);
        return res;
    }
};