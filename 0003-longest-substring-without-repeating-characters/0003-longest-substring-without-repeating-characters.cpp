class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size(), st = 0, en = 0, mx = 0;
        while(en < n)
        {
            mp[s[en]]++;
            while(mp[s[en]] > 1) 
            {
                mp[s[st]]--;
                st++;
            }
            mx = max(mx, en - st + 1);
            en++;
        }
        return mx;
    }
};