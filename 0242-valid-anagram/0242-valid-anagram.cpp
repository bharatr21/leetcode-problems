class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if(m != n) return false;
        // Put it into two character frequency maps, then check if they are same
        unordered_map<char, int> ms, mt;
        for(char ch: s) ms[ch]++;
        for(char ch: t) mt[ch]++;
        for(auto u: ms)
        {
            if(mt[u.first] != u.second) return false;
        }
        return true;
    }
};