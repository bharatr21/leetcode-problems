class Solution {
public:
    bool isValid(unordered_map<char, int> &hs, unordered_map<char, int> &ht) {
        for(auto u: ht)
        {
            if(u.second > hs[u.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for(char c: t) ht[c]++;
        int m = t.size(), n = s.size(), st = 0, en = 0, rst, ren;
        int mn = n + 2;
        while(en < n)
        {
            hs[s[en++]]++;
            while(en - st >= m && isValid(hs, ht))
            {
                if(mn > en - st + 1)
                {
                    mn = en - st + 1;
                    rst = st;
                    ren = en;
                }
                hs[s[st++]]--;
            }
        }
        return ((mn == n + 2) ? "": s.substr(rst, ren - rst));
    }
};