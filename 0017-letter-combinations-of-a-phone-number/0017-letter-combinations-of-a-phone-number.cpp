class Solution {
public:
    void backtrack(string digits, int idx, unordered_map<char, string>& digitMap, string tmp, vector<string>& res) {
        if(idx == digits.size()) {
            res.push_back(tmp);
            return;
        }
        if(!digitMap.count(digits[idx])) idx++;
        else {
            for(char ch: digitMap[digits[idx]]) {
                tmp += ch;
                backtrack(digits, idx + 1, digitMap, tmp, res);
                tmp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string tmp;
        unordered_map<char, string> digitMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.empty()) return res;
        backtrack(digits, 0, digitMap, tmp, res);
        return res;
    }
};