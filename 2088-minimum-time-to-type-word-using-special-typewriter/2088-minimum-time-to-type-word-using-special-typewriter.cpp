class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
        char cur = 'a';
        for(char ch: word) {
            int diff = abs(cur - ch);
            res += min(diff + 1, 27 - diff);
            cur = ch;
        }
        return res;
    }
};