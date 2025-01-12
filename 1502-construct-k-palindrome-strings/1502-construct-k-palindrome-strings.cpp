class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        vector<int> fr(26, 0);
        for(char ch: s) fr[ch - 'a']++;
        int oddf = 0;
        for(int i = 0; i < 26; i++) oddf += (fr[i] % 2);
        if(oddf > k) return false;
        return true;
    }
};