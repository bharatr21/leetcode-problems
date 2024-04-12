class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fs, ft;
        for(char c: s) fs[c]++;
        for(char c: t) ft[c]++;
        for(auto u: fs)
        {
            if(ft.find(u.first) == ft.end() || ft[u.first] != u.second) return false;
        }
        for(auto u: ft)
        {
            if(fs.find(u.first) == fs.end() || fs[u.first] != u.second) return false;
        }
        return true;
    }
};
