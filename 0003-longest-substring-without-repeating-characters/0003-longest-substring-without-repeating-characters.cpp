class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(!n) return 0;
        unordered_map<char, int> hash;
        int st = 0, en = 0, rst, ren, mx = 0, rep = 0;
        while(en < n) {
            hash[s[en]]++;
            if(hash[s[en]] == 2) rep++;
            while(rep > 0) {
                hash[s[st]]--;
                if(hash[s[st]] == 1) rep--;
                else if(hash[s[st]] == 0) hash.erase(s[st]);
                st++;
            }
            if(mx < en - st + 1) {
                mx = en - st + 1;
                rst = st;
                ren = en;
            }
            en++;
        }
        cout << s.substr(rst, ren - rst + 1);
        return mx;
    }
};