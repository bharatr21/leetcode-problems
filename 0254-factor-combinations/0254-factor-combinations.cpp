class Solution {
public:
    void backtrack(vector<int>& factors, vector<vector<int>>& res) {
        if(factors.size() > 1) res.push_back(factors);
        int last = factors.back();
        factors.pop_back();
        for(int i = factors.empty() ? 2 : factors.back(); i <= last / i; i++) {
            if(last % i == 0) {
                factors.push_back(i);
                factors.push_back(last / i);
                backtrack(factors, res);
                factors.pop_back();
                factors.pop_back();
            }
        }
        factors.push_back(last);
    }

    vector<vector<int>> getFactors(int n) {
        vector<int> factors = {n};
        vector<vector<int>> res;
        backtrack(factors, res);
        return res;
    }
};