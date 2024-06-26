class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // Needed for min-heap (default is max-heap)
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(int n: nums) pq.push(n);
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > sz) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */