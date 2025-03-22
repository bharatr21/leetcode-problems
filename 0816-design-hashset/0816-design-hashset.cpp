class MyHashSet {
public:
    int MOD;
    vector<vector<int>> v;
    MyHashSet() {
        MOD = 1009;
        v.resize(MOD);
    }
    
    void add(int key) {
        int hash = key % MOD;
        auto it = find(v[hash].begin(), v[hash].end(), key);
        if(it == v[hash].end()) {
            v[hash].push_back(key);
        }
    }
    
    void remove(int key) {
        int hash = key % MOD;
        auto it = find(v[hash].begin(), v[hash].end(), key);
        if(it != v[hash].end()) {
            v[hash].erase(it);
        }
    }
    
    bool contains(int key) {
        int hash = key % MOD;
        auto it = find(v[hash].begin(), v[hash].end(), key);
        return (it != v[hash].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */