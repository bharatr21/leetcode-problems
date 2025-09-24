class Solution {
public:
    bool checkNZ(int n) {
        if(!n) return false;
        int tmp = n;
        while(tmp) {
            if(!(tmp % 10)) return false;
            tmp /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 0; i <= (n + 1)/2; i++) {
            if(checkNZ(i) && checkNZ(n - i)) return {i, n-i};
        }
        return {1, n-1};
    }
};