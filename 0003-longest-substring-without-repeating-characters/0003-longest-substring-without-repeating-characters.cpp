class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> hash;
        int n = s.size(), st = 0, en = 0, dup = 0, mx = 0;
        while(en < n) {
            hash[s[en]]++;
            if(hash[s[en]] == 2) dup++;
            while(st < n && dup > 0) {
                hash[s[st]]--;
                if(hash[s[st]] == 1) dup--;
                st++;
            }
            mx = max(mx, en - st + 1);
            en++;
        }
        return mx;
    }
};