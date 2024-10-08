class Solution {
public:
    int minSwaps(string s) {
        int res = 0;
        for(char ch: s) {
            if(ch == '[') res++;
            else {
                if(res) res--;
            }
        }
        return (res + 1) / 2;
    }
};