class Solution {
public:
    string countAndSay(int n) {
        string res;
        if(n == 1) return "1";
        int rl = 0;
        char prev;
        for(char ch: countAndSay(n - 1)) {
            if(!rl) {
                rl = 1;
                prev = ch;
            }
            else if(prev == ch) rl++;
            else {
                res += to_string(rl) + prev;
                prev = ch;
                rl = 1;
            }
        }
        res += to_string(rl) + prev;
        return res;
    }
};