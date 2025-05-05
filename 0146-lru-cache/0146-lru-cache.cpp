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
        if(it == lru.end()) return -1;
        int val = it->second->second;
        auto iter = it->second;
        lru.erase(key);
        cache.erase(iter);
        cache.push_front({key, val});
        lru[key] = cache.begin();
        return val;
    }
    
    void put(int key, int value) {
        auto it = lru.find(key);
        if(it != lru.end()) {
            lru.erase(key);
            cache.erase(it->second);
        }
        cache.push_front({key, value});
        lru[key] = cache.begin();
        if(cache.size() > cap) {
            int key = cache.back().first;
            lru.erase(key);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */