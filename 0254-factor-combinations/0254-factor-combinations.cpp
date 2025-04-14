class Solution {
public:
    void solve(int idx, vector<int>& factors, vector<int>& tmp, int rem, set<vector<int>>& res) {
        int n = factors.size();
        if(idx >= n) return;
        if(rem == 1) {res.insert(tmp); return;}
        for(int i = idx; i < n; i++) {
            if(rem % factors[i] == 0) {
                tmp.push_back(factors[i]);
                rem = rem / factors[i];
                solve(i, factors, tmp, rem, res);
                tmp.pop_back();
                rem = rem * factors[i];
                solve(i + 1, factors, tmp, rem, res);
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        set<vector<int>> res;
        vector<int> factors, tmp;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                factors.push_back(i);
                factors.push_back(n / i);
            }
        }
        sort(factors.begin(), factors.end());
        solve(0, factors, tmp, n, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
