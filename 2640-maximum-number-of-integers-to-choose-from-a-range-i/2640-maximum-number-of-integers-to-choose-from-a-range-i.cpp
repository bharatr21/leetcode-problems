class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        unordered_set<int> s(v.begin(), v.end());
        for(int el: banned) {
            if(s.count(el)) s.erase(el);
        }
        vector<int> f(s.begin(), s.end());
        sort(f.begin(), f.end());
        int m = f.size(), cumsum = 0;
        for(int i = 0; i < m; i++) {
            if(cumsum + f[i] > maxSum) return i;
            cumsum += f[i];
        }
        return m;
    }
};