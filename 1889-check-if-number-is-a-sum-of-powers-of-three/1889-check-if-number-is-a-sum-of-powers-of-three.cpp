class Solution {
public:
    bool checkPowersOfThree(int n) {
        int tmp = n;
        while(tmp) {
            if(tmp % 3 == 2) return false;
            tmp = tmp / 3;
        }
        return true;
    }
};