class Solution {
public:
    bool checkPowersOfThree(int n) {
        int tmp = n;
        vector<short> res;
        while(tmp) {
            res.push_back(tmp % 3);
            tmp = tmp / 3;
        }
        for(int el: res) {
            if(el == 2) return false;
        }
        return true;
    }
};