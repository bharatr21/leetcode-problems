class LRUCache {
public:
    deque<int> dq;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> lru;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});
        mp.erase(it);
        mp[key] = lru.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            lru.erase(it->second);
            mp.erase(it);
        }
        lru.push_front({key, value});
        mp[key] = lru.begin();

        if(mp.size() > cap) {
            auto it2 = lru.rbegin();
            auto it = mp.find(it2->first);
            mp.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */