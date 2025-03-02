class Solution {
public:
    void permuteHelper(int n, vector<int>& tmp, vector<vector<int>>& res, bool parity, unordered_set<int>& even, unordered_set<int>& odd) {
        if(tmp.size() == n) {
            res.push_back(tmp);
            return;
        }
        else {
            if(parity) {
                for(int i = 2; i <= n; i+=2) {
                    if(even.count(i)) continue;
                    tmp.push_back(i);
                    even.insert(i);
                    permuteHelper(n, tmp, res, i % 2, even, odd);
                    tmp.pop_back();
                    even.erase(i);
                }
            } else {
                for(int i = 1; i <= n; i+=2) {
                    if(odd.count(i)) continue;
                    tmp.push_back(i);
                    odd.insert(i);
                    permuteHelper(n, tmp, res, i % 2, even, odd);
                    tmp.pop_back();
                    odd.erase(i);
                }
            }
        }
    }
    vector<vector<int>> permute(int n) {
        unordered_set<int> even, odd;
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i = 1; i <= n; i++) {
            tmp.push_back(i);
            if(i % 2) odd.insert(i);
            else even.insert(i);
            permuteHelper(n, tmp, res, i % 2, even, odd);
            tmp.pop_back();
            if(i % 2) odd.erase(i);
            else even.erase(i);
        }
        //sort(res.begin(), res.end())
        return res;
    }
};