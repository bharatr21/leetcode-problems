class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long res = 0;
        priority_queue<int> pq;
        for(int el: gifts) pq.push(el);
        for(int i = 0; i < k; i++) {
            int el = pq.top();
            int tmp = int(sqrt(el));
            pq.pop();
            pq.push(tmp);
        }
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};