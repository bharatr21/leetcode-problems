class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), ct = 1;
        vector<int> groups;
        for(int i = 1; i < n; i++) {
            if(s[i-1] != s[i]) {
                groups.push_back(ct);
                ct = 1;
            }
            else ct++;
        }
        groups.push_back(ct);
        int m = groups.size(), res = 0;
        for(int i = 0; i < m - 1; i++) res += min(groups[i], groups[i+1]);
        return res;
    }
};