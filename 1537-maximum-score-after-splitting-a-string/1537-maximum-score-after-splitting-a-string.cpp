class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int res = 0;
        int ones = count(s.begin(), s.end(), '1');
        int zeros = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '1') ones--;
            else zeros++;
            res = max(res, zeros + ones);
        }
        return res;
    }
};