class Solution {
public:
    string prefix(string& str1, string& str2) {
        int m = str1.size(), n = str2.size(), i;
        for(i = 0; i < min(m, n); i++) {
            if(str1[i] != str2[i]) break;
        }
        return str1.substr(0, i);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string pre;
        if(n == 1) return strs[0];
        else {
            pre = prefix(strs[0], strs[1]);
            for(int i = 2; i < n; i++) {
                pre = prefix(pre, strs[i]);
            }
        }
        return pre;
    }
};