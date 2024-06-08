class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int n = s.size(), i, j;
        vector<bool> mark(n, false);
        for(i = 0; i < n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9') {
                mark[i] = true;
                for(j = i - 1; j >= 0; j--)
                {
                    if(!(s[j] >= '0' && s[j] <= '9'))
                    {
                        if(!mark[j]) {mark[j] = true; break;}
                    }
                }
            }
        }
        for(i = 0; i < n; i++) {
            if(!mark[i]) ans += s[i];
        }
        return ans;
    }
};