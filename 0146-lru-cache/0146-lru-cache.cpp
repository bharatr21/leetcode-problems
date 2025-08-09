class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> lru;
    list<pair<int, int>> cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = lru.find(key);
        if(it != lru.end()) {
            int val = it->second->second;
            cache.erase(it->second);
            cache.push_front({key, val});
            lru[key] = cache.begin();
            return val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        auto it = lru.find(key);
        if(it != lru.end()) {
            cache.erase(it->second);
        } else {
            if(lru.size() == cap) {
                auto [key, val] = cache.back();
                cache.pop_back();
                lru.erase(key);
            }
        }
        cache.push_front({key, value});
        lru[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */