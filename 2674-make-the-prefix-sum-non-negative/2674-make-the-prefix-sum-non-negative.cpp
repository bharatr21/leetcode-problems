class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int ops = 0;
        long pre = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n: nums) {
            if(n < 0) pq.push(n);
            pre += n;
            if(pre < 0) {
                int el = pq.top();
                pq.pop();
                pre -= el;
                ops++;
            }
        }
        return ops;
    }
};