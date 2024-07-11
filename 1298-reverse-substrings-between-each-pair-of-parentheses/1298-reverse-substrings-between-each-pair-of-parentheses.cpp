class Solution {
public:
    pair<string, int> helper(string s, int idx) {
        pair<string, int> resp;
        string res;
        while(s[idx] != ')')
        {
            if(s[idx] == '(') {
                resp = helper(s, idx+1);
                res += resp.first;
                idx = resp.second;
            }
            else {
                res += s[idx];
                idx++;
            }

        }
        reverse(res.begin(), res.end());
        return {res, idx+1};
    }
    string reverseParentheses(string s) {
        int n = s.size();
        pair<string, int> resp;
        string res;
        for(int idx = 0; idx < n;)
        {
            if(s[idx] == '(')
            {
                resp = helper(s, idx+1);
                res += resp.first;
                idx = resp.second;
            }
            else {
                res += s[idx];
                idx++;
            }
        }
        return res;
    }
};