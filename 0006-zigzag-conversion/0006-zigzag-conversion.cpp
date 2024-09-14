class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = numRows, i = 0;
        vector<string> v(n);
        int sgn = -1;
        for(char ch: s) {
            if(i == 0 || i == n - 1) sgn *= -1;
            v[i] += ch;
            i = (i + sgn * 1) % n;
        }
        for(string els: v) {
            res += els;
        }
        return res;
    }
};