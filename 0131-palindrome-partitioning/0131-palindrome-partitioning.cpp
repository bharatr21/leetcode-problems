class Solution {
public:
    bool ispal(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    } 
    void solve(string s, int idx, vector<string>& tmp, vector<vector<string>>& res) {
        if(idx == s.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int i = idx; i < s.size(); i++)
        {
            if(ispal(s, idx, i))
            {
                tmp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i+1, tmp, res);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        solve(s, 0, tmp, res);
        return res;
    }
};