class Solution {
public:
    bool isUgly(int n) {
        int temp = n;
        if(temp <= 0) return false;
        while(temp > 1) {
            if(temp % 2 == 0) temp = temp / 2;
            else if(temp % 3 == 0) temp = temp / 3;
            else if(temp % 5 == 0) temp = temp / 5;
            else return false;
        }
        return (temp == 1);
    }
};