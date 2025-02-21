class MRUQueue {
public:
    vector<int> v; 
    MRUQueue(int n) {
        for(int i = 1; i <= n; i++) {
            v.push_back(i);
        }
    }
    
    int fetch(int k) {
        auto it = (v.begin() + k - 1);
        int el = *it;
        v.erase(it);
        v.push_back(el);
        return el;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */