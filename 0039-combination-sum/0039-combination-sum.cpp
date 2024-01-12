class Solution {
public:
    void backtrack(vector<int>& candidates, int start, int end, int target, vector<int> &temp, vector<vector<int>> &res)
    {
        if(target < 0 || start >= end) return;
        if(target == 0) {
            res.push_back(temp); 
            return;
        }
        temp.push_back(candidates[start]);
        backtrack(candidates, start, end, target - candidates[start], temp, res);
        temp.pop_back();
        backtrack(candidates, start + 1, end, target, temp, res);
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> res;
        backtrack(candidates, 0, n, target, temp, res);
        return res;   
    }
};