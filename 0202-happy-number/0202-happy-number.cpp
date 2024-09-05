class Solution {
public:
    int sumd(int n) {
        int temp = n, res = 0;
        while(temp) {
            res += (temp % 10) * (temp % 10);
            temp /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(!seen.count(n) && n != 1) {
            seen.insert(n);
            n = sumd(n);
        }
        return (n == 1);
    }
};