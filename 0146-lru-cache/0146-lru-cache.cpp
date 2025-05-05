class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> lru;
    list<pair<int, int>> cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!lru.count(key)) return -1;
        auto it = lru[key];
        int val = it->second;
        lru.erase(key);
        cache.erase(it);
        cache.push_front({key, val});
        lru[key] = cache.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(lru.count(key)) {
            auto it = lru[key];
            cache.erase(it);
            lru.erase(key);
        }
        cache.push_front({key, value});
        lru[key] = cache.begin();
        if(cache.size() > cap) {
            int key = cache.back().first;
            cache.pop_back();
            lru.erase(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */