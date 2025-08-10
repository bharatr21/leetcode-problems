class Solution {
public:
    bool ndigits(int n) {
        int tmp = n, ct = 0;
        while(tmp) {
            ct++;
            tmp /= 10;
        }
        return ct;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> pow2, ndig;
        for(int i = 0; i <= 30; i++) {
            pow2.push_back(1 << i);
            ndig.push_back(ndigits(1 << i));
        }
        int tmp = n;
        int dig = ndigits(tmp);
        string s1 = to_string(tmp);
        sort(s1.begin(), s1.end());
        auto [lb, ub] = equal_range(ndig.begin(), ndig.end(), dig);
        int lo = distance(ndig.begin(), lb);
        int hi = distance(ndig.begin(), ub);
        if(lo <= hi && hi <= ndig.size()) {
            for(int i = lo; i <= hi; i++) {
                string s2 = to_string(pow2[i]);
                sort(s2.begin(), s2.end());
                if(s1 == s2) return true;
            }
        }
        return false;
    }
};