class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), i;
        int lo = 0, hi = 0;
        for(char ch: s)
        {
            lo += ((ch == '(') ? 1: -1);
            hi += ((ch != ')') ? 1: -1);
            if(hi < 0) break;
            lo = max(lo, 0);
        }
        return (lo == 0);
    }
};