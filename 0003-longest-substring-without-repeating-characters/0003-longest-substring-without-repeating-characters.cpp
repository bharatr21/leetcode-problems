class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), st = 0, en = 0, d = 0, res = 0;
        unordered_map<char, int> hash;
        while(st < n && en < n) {
            hash[s[en]]++;
            if(hash[s[en]] > 1) d++;
            en++;
            while(d) {
                if(--hash[s[st]] == 1) d--;
                st++;
            }
            res = max(res, en - st);
        }
        return res;
    }
};