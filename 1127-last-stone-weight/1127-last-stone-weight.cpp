class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        if(n == 1) return stones[0];
        if(n == 2) return abs(stones[1] - stones[0]);
        for(int stone: stones) pq.push(stone);
        while(pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(abs(b - a) > 0) pq.push(abs(b - a));
        }
        return (pq.empty() ? 0: pq.top());
    }
};