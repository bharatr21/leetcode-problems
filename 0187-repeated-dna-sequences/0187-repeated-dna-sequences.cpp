class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        unordered_set<string> str, result;
        if(n <= 10) return res;
        string tmp;
        for(int i = 0; i < 10; i++) {
            tmp += s[i];
        }
        str.insert(tmp);
        for(int i = 10; i < n; i++) {
            tmp += s[i];
            tmp = tmp.substr(1);
            if(str.count(tmp)) result.insert(tmp);
            else str.insert(tmp);
        }
        res.assign(result.begin(), result.end());
        return res;
    }
};