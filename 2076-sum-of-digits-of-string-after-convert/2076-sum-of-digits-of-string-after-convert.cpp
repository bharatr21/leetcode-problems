class Solution {
public:
    int sumds(string s) {
        int res = 0;
        for(char ch: s) {
            res += (ch - '0');
        }
        return res;
    }

    int sumd(int s) {
        int tmp = s, res = 0;
        while(tmp) {
            res += tmp % 10;
            tmp = tmp / 10;
        }
        return res;
    }

    int getLucky(string s, int k) {
        string res;
        int n;
        for(char ch: s) {
            res += to_string(ch - 'a' + 1);
        }
        n = sumds(res);
        for(int i = 2; i <= k; i++) {
            n = sumd(n);
        }
        return n;
    }
};