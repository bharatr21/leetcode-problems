class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> seen;
        long cur;
        pq.push(1);
        seen.insert(1);
        for(int i = 0; i < n; i++) {
            cur = pq.top();
            pq.pop();
            if(!seen.count(cur * 2)) {pq.push(cur * 2); seen.insert(cur * 2); }
            if(!seen.count(cur * 3)) {pq.push(cur * 3); seen.insert(cur * 3); }
            if(!seen.count(cur * 5)) {pq.push(cur * 5); seen.insert(cur * 5); }
        }
        return (int)cur;
    }
};