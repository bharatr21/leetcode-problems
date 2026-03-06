class Solution {
public:
    bool checkOnesSegment(string s) {
        vector<int> ones;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') ones.push_back(i);
        }
        int m = ones.size();
        for(int i = 1; i < m; i++) {
            if(ones[i] - ones[i-1] != 1) return false;
        }
        return true;
    }
};