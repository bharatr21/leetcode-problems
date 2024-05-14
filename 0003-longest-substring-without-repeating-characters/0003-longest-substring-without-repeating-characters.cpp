class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(128, 0);
        int start = 0, end = 0, window = 0, ans = 0, n = s.size();
        while(end < n) {
            /* First the condition check happens, then the hash[x]++ or hash[x]-- operations, then the actual start and end get inc/decremented */
            if(hash[s[end]]++ > 0) {
                window++;
            }
            end++;
            while(window > 0) {
                if(hash[s[start]]-- > 1) {
                    window--;
                }
                start++;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};