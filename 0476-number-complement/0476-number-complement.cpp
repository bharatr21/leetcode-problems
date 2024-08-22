class Solution {
public:
    int findComplement(int num) {
        int temp = num, res = 0, val = 1;
        while(temp) {
            if(!(temp & 1)) res += val;
            temp = temp >> 1;
            val = val << 1;
        }
        return res;
    }
};