class Solution {
public:
    bool checkString(string s) {
        int n = s.size(), mxa, mnb, i;
        for(i = n - 1; i >= 0; i--) {
            if(s[i] == 'a') {mxa = i; break;}
        }
        for(i = 0; i < n; i++) {
            if(s[i] == 'b') {mnb = i; break;}
        }
        return (mxa < mnb);
    }
};