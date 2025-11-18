class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        vector<bool> st_ch(n, false);
        st_ch[0] = true;
        for(int i = 0; i < n;) {
            if(bits[i]) {
                if(i <= n-2) i+=2;
            } else {
                i++;
            }
            if(i < n) st_ch[i] = true;
        }
        return st_ch[n-1];
    }
};