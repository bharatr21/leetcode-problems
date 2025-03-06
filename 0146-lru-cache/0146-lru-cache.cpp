class LRUCache {
public:
    map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> lru;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            auto listpos = it->second;
            int val = listpos->second;
            lru.erase(listpos);
            lru.push_front({key, val});
            mp[key] = lru.begin();
            return val;
        } else return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            auto listpos = it->second;
            lru.erase(listpos);
        }
        lru.push_front({key, value});
        mp[key] = lru.begin();
        if(lru.size() > cap) {
            auto [key, val] = lru.back();
            lru.pop_back();
            mp.erase(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */