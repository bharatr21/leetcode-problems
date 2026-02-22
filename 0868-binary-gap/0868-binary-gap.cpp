class Solution {
public:
    int binaryGap(int n) {
        vector<int> ones;
        int t = n;
        string s;
        while(t) {
            s += (t % 2) + '0';
            t >>= 1;
        }
        for(size_t i = 0; i < s.size(); i++) {
            if(s[i] == '1') ones.push_back(i);
        }
        int sz = ones.size(), mx = 0;
        for(int i = 1; i < sz; i++) {
            mx = max(mx, ones[i] - ones[i-1]);
        }
        return mx;
    }
};