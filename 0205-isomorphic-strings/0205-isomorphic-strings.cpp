class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smap, tmap;
        int n = s.size(), i;
        for(i = 0; i < n; i++)
        {
            if(smap.find(s[i]) == smap.end() && tmap.find(t[i]) == tmap.end())
            {
                smap[s[i]] = t[i];
                tmap[t[i]] = s[i];
            }
            else if(smap[s[i]] != t[i] || tmap[t[i]] != s[i]) return false;
         }
        return true;
    }
};