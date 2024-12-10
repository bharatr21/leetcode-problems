class Solution {
public:
    bool isSpecial(string s) {
        char f = s[0];
        for(char ch: s) {
            if(ch != f) return false;
        }
        return true;
    }
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int mx = -1;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string tmp = s.substr(i, j-i+1);
                if(isSpecial(tmp)) mp[tmp]++;
            }
        }
        for(auto u: mp) {
            if(u.second >= 3) {
                mx = max(mx, (int)u.first.size());
            }
        }
        return mx;
    }
};