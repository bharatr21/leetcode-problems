class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int m = a.size(), n = b.size();
        if(m != n) {
            if(m < n) {
                for(int j = m; j < n; j++) a += '0';
            } else {
                for(int j = n; j < m; j++) b += '0';
            }
        }
        m = a.size(); 
        int carry = 0, k;
        for(int i = 0; i < m; i++) {
            res += ((carry + (a[i] - '0') + (b[i] - '0')) % 2) + '0';
            carry = (carry + (a[i] - '0') + (b[i] - '0')) / 2;
        }
        if(carry > 0) res += '1';
        reverse(res.begin(), res.end());
        if(res == "0") return res;
        else {
            k = 0;
            while(res[k] == '0') k++;
        }
        return res.substr(k);
    }
};