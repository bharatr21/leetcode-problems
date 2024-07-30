class Solution {
public:
    bool checkString(string s) {
        int n = s.size(), mxa, mnb, i;
        for(i = 0; i < n; i++) {
            if(s[i] == 'b') {mnb = i; break;}
        }
        for(i = mnb; i < n; i++) {
            if(s[i] == 'a') return false;
        }
        return true;
    }
};