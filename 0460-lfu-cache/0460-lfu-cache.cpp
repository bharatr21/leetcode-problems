class LFUCache {
public:
    unordered_map<int, list<pair<int, int>>> frequencies; 
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int cap;
    int minf;
    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
    }

    void insert(int key, int freq, int val) {
        frequencies[freq].push_back({key, val});
        cache[key] = {freq, --frequencies[freq].end()};
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        auto [f, iter] = it->second;
        pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if(frequencies[f].empty()) {
            frequencies.erase(f);
            if(minf == f) minf++;
        }
        insert(key, f + 1, kv.second);
        return kv.second;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        auto it = cache.find(key);
        if(it != cache.end()) {
            auto iter = it->second;
            auto kv = iter.second;
            kv->second = value;
            get(key);
            return;
        }
        if(cap == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();
            if(frequencies[minf].empty()) frequencies.erase(minf);
        }
        minf = 1;
        insert(key, 1, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */