class Solution {
public:
    int k(char ch) {return ch - '0';}
    int diff(string s1, string s2) {
        int n = s1.size(), ct = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) ct++;
        }
        return ct;
    }

    int minOperations(string s) {
        int n = s.size(), op1, op2;
        string tgt;
        for(int i = 1; i <= n/2; i++) tgt += "01";
        if(n % 2) tgt += '0';
        op1 = diff(s, tgt);
        tgt.clear();
        for(int i = 1; i <= n/2; i++) tgt += "10";
        if(n % 2) tgt += '1';
        op2 = diff(s, tgt);
        return min(op1, op2);
    }
};