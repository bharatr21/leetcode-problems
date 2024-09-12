class Solution {
public:
    bool consistent(unordered_set<char> &allowList, string s) {
        for(char ch: s) {
            if(!allowList.count(ch)) return false;
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowList(allowed.begin(), allowed.end());
        int res = 0;
        for(string word: words) {
            res += consistent(allowList, word);
        }
        return res;
    }
};