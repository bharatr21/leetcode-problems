class MyHashMap {
public:
    vector<list<pair<int, int>>> v;
    int MOD;
    MyHashMap() {
        MOD = 1009;
        v.resize(MOD);
    }

    int hash(int key) {return key % MOD;}
    
    void put(int key, int value) {
        int hash_key = hash(key);
        for(auto& it: v[hash_key]) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        v[hash_key].push_back({key, value});
    }
    
    int get(int key) {
        int hash_key = hash(key);
        for(auto& it: v[hash_key]) {
            if(it.first == key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = hash(key);
        for(auto it = v[hash_key].begin(); it != v[hash_key].end(); it++) {
            if(it->first == key) {
                v[hash_key].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */