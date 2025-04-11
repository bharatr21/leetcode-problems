class Solution {
public:
    bool symmetric(vector<int>& digits) {
        int n = digits.size(), lsum = 0, rsum = 0;
        if(n % 2) return false;
        for(int i = 0; i <= (n - 1)/2; i++) lsum += digits[i];
        for(int i = n/2; i < n; i++) rsum += digits[i];
        return (lsum == rsum);
    }

    vector<int> exd(int n) {
        int tmp = n;
        vector<int> res;
        while(tmp) {
            res.push_back(tmp % 10);
            tmp /= 10;
        }
        return res;
    }

    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++) {
            vector<int> digits = exd(i);
            if(symmetric(digits)) res++;
        }
        return res;
    }
};