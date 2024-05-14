class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), begin = 0, end = 0, d = INT_MIN, counter = 0;
        unordered_map<char, int> m;
        while(end < n)
        {
            if(m[s[end++]]++ > 0) counter++;
            while(counter > 0)
            {
                if(m[s[begin++]]-- > 1) counter--;
            }
            d = max(d, end - begin);
        }
        return ((d == INT_MIN) ? 0: d);
    }
};