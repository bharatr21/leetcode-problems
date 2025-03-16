class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        long long pow = 1;
        for(int i = n - 1; i >= 0; i--) {
            res += pow * (columnTitle[i] - 'A' + 1);
            pow = pow * 26;
        }
        return res;
    }
};