class Solution {
public:
    void solve(string digits, unordered_map<char, string>& nmap, string& tmp, vector<string>& res)
    {
        if(tmp.size() == digits.size())
        {
            if(!tmp.empty()) res.push_back(tmp);
            return;
        }
        int idx = tmp.size();
        for(char c: nmap[digits[idx]])
        {
            tmp += c;
            solve(digits, nmap, tmp, res);
            tmp.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> nmap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string tmp;
        vector<string> res;
        solve(digits, nmap, tmp, res);
        return res;
    }
};