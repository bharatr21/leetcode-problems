class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int n = s.size();
        vector<bool> del(n, false);
        for(int i = 1; i < n - 1; i++) {
            if(!del[i] && (s[i-1] == s[i] && s[i] == s[i+1])) del[i] = true;
        }
        for(int i = 0; i < n; i++) {
            if(!del[i]) res += s[i];
        }
        return res;
    }
};