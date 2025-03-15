class Solution {
public:
    string betterCompression(string compressed) {
        string res;
        int fre = 0, idx = -1;
        vector<int> alp(26, 0);
        for(char ch: compressed) {
            if(isalpha(ch)) {
                if(idx != -1) alp[idx] += fre;
                idx = ch - 'a';
                fre = 0;
            }
            else if(isdigit(ch)) {
                fre = fre * 10 + (ch - '0');
            }
        }
        alp[idx] += fre;
        for(int i = 0; i < 26; i++) {
            if(alp[i] > 0) {
                res += (char)(i + 'a') + to_string(alp[i]);
            }
        }
        return res;
    }
};