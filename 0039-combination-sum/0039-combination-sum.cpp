class Solution {
public:
    void combi(vector<vector<int>>& res, vector<int>& tmp, vector<int>& candidates, int st, int target) {
        int n = candidates.size();
        if(target < 0 || st >= n) return;
        else if(target == 0) {res.push_back(tmp); return;}
        else {
            for(int i = st; i < n; i++) {
                tmp.push_back(candidates[i]);
                combi(res, tmp, candidates, i, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combi(res, tmp, candidates, 0, target);
        return res;
    }
};