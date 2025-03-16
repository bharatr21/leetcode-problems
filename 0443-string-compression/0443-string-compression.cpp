class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0, n = chars.size();
        while(i < n) {
            int rl = 1; //Run-length
            while(i + rl < n && chars[i + rl] == chars[i]) rl++;
            chars[res++] = chars[i];
            if(rl > 1) {
                for(char c: to_string(rl)) {
                    chars[res++] = c;
                }
            }
            i += rl;
        }
        return res;
    }
};