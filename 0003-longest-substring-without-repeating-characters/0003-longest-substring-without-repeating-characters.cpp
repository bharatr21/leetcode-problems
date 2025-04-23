class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int n = s.size();
        int st = 0, d = 0, mx = 0;
        for(int en = 0; en < n; en++) {
            hash[s[en]]++;
            if(hash[s[en]] == 2) d++;
            while(d) {
                hash[s[st]]--;
                if(hash[s[st]] == 1) d--;
                st++;
            }
            mx = max(mx, en - st + 1);
        }
        return mx;
    }
};