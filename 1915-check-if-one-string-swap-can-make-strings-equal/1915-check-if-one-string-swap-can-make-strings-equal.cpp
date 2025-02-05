class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ff = -1, ss = -1, uneq = 0;
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
               uneq++;
               if(ff == -1) ff = i;
               else if(ss == -1) ss = i;
               else return false; 
            }
        }
        if(uneq == 0) return true;
        if(uneq == 2) {return (s1[ff] == s2[ss] && s2[ff] == s1[ss]);}
        return false;
    }
};