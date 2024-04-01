class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> hash(128, 0);
        int n = s.size(), start = 0, end = 0, uniq = 0, res = 0;
        while(end < n)
        {
            if(hash[s[end]]++ == 0) uniq++;
            end++;
            while(uniq > 2 && start < n)
            {
                if(hash[s[start]]-- == 1) uniq--;
                start++;
            }
            res = max(res, end - start);
        }
        return res;
    }
};