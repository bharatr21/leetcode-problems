class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto temp = n;
        int ct = 0;
        while(temp)
        {
            if(temp & 1) ct++;
            temp = temp >> 1;
        }
        return ct;
    }
};