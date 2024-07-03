class Solution {
public:
    bool isPal(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& tmp, int st, int en, string s) {
        if(st >= en) {
            res.push_back(tmp);
            return;
        }
        for(int i = st; i < en; i++) {
            if(isPal(s.substr(st, i - st + 1))) {
                tmp.push_back(s.substr(st, i - st + 1));
                backtrack(res, tmp, i+1, en, s);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        int n = s.size();
        backtrack(res, tmp, 0, n, s);
        return res;
    }
};