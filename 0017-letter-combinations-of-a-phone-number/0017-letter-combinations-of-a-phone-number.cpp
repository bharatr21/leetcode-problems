class Solution {
public:
    void backtrack(vector<string>& res, string tmp, string digits, unordered_map<char, vector<string>>& mp, int idx) {
        if(idx == digits.size()) {
            res.push_back(tmp);
            return;
        }
        for(string d: mp[digits[idx]]) {
            tmp += d;
            backtrack(res, tmp, digits, mp, idx + 1);
            tmp.erase(idx);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        string tmp;
        unordered_map<char, vector<string>> mp = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };
        backtrack(res, tmp, digits, mp, 0);
        return res;
    }
};