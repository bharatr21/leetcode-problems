class Solution {
public:
    string compressedString(string word) {
        string res;
        char cur;
        int rl = 0;
        for(char ch: word) {
            if(cur == ch && rl < 9) {
                rl++;
            }
            else if(cur != ch || rl == 9) {
                res += to_string(rl) + cur;
                cur = ch;
                rl = 1;
            }
        }
        res += to_string(rl) + cur;
        return res.substr(2);
    }
};