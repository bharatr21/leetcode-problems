class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while(res.size() < k) {
            string tmp;
            for(char ch: res) {
                if(ch == 'z') tmp += 'a';
                else tmp += (ch + 1);
            }
            res += tmp;
        }
        return res[k-1];
    }
};