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
            auto cache_it = it->second;
            int val = cache_it->second;
            cache.erase(cache_it);
            cache.push_front({key, val});
            lru[key] = cache.begin();
            return val;
        } else return -1;
    }
    
    void put(int key, int value) {
        if(lru.count(key)) {
            auto cache_it = lru[key];
            cache.erase(cache_it);
        } else if(cache.size() == cap) {
            auto [bkey, bval] = cache.back();
            lru.erase(bkey);
            cache.pop_back();
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