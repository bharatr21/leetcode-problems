class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int i = 0, st = 0, en = 0;
        int n = s.size(), res = 0;
        while(en < n && i <= k)
        {
            if(mp[s[en]] == 0)
            {
                i++;
            }
            mp[s[en]]++;
            en++;
            while(i > k && st < n)
            {
                if(--mp[s[st]] == 0) i--;
                st++;
            }
            // cout << s.substr(st, en - st) << "\n";
            res = max(res, en - st);
        }
        return res;
    }
};