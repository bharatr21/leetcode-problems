class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char, int> fres, fret;
        for(char ch: s) fres[ch]++;
        for(char ch: t) fret[ch]++;
        for(auto u: fres) {
            if(u.second != fret[u.first]) return false;
        }
        return true;
    }
};