class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        set<int> letters;
        int n = s.size(), res = 0, st = 0, en = 0, ct = 0;
        for(char ch: s) letters.insert(ch);
        for(char letter: letters) {
            st = 0;
            ct = 0;
            for(en = 0; en < n; en++) {
                if(s[en] == letter) ct++;
                while(en - st + 1 - ct > k) {  // Invalid Window Condition
                    if(s[st] == letter) ct--;
                    st++;
                }
                res = max(res, en - st + 1);
            }
        }
        return res;
    }
};