class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        for(char ch: s) mp[ch]++;
        bool flag = true;
        for(auto u: mp) {
            if(u.second % 2 != 0 && flag) {
                res += u.second;
                flag = false;
            }
            else res += (u.second / 2) * 2;
        }
        return res;
    }
};