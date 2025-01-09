class Solution {
public:
    bool containsPref(string s, string pref) {
        int m = pref.size();
        for(int i = 0; i < m; i++) {
            if(s[i] != pref[i]) return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(string word: words) {
            if(containsPref(word, pref)) res++;
        }
        return res;
    }
};