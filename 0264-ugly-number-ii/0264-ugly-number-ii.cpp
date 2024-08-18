class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> res;
        long cur;
        res.insert(1);
        for(int i = 0; i < n; i++) {
            cur = *res.begin();
            res.erase(cur);
            res.insert(cur * 2);
            res.insert(cur * 3);
            res.insert(cur * 5);
        }
        return (int)cur;
    }
};