class AllOne {
    struct Node {
        int freq;
        unordered_set<string> keys;
    };
    list<Node> freqList;
    unordered_map<string, list<Node>::iterator> key2it;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        // Find current node (or create a frequency-0 dummy)
        auto it = key2it.count(key)
                  ? key2it[key]
                  : freqList.insert(freqList.begin(), Node{0, {}});
        int f = it->freq;
        auto next = std::next(it);

        // Ensure the next node has freq = f+1
        if (next == freqList.end() || next->freq != f + 1) {
            next = freqList.insert(next, Node{f + 1, {}});
        }

        // Move key to next node
        next->keys.insert(key);
        key2it[key] = next;
        
        // Remove from old node; if empty, erase it
        if (it->keys.erase(key), it->keys.empty()) {
            freqList.erase(it);
        }
    }
    
    void dec(string key) {
        auto mapIt = key2it.find(key);
        if (mapIt == key2it.end()) return;  // Key not present

        auto nodeIt = mapIt->second;
        int f = nodeIt->freq;
        nodeIt->keys.erase(key);

        if (f > 1) {
            auto prev = (nodeIt == freqList.begin())
                        ? freqList.end()
                        : std::prev(nodeIt);
            // Ensure the previous node has freq = f-1
            if (prev == freqList.end() || prev->freq != f - 1) {
                prev = freqList.insert(nodeIt, Node{f - 1, {}});
            }
            prev->keys.insert(key);
            key2it[key] = prev;
        } else {
            // Frequency hits zero: remove key entirely
            key2it.erase(mapIt);
        }

        // If old node is empty now, erase it
        if (nodeIt->keys.empty()) {
            freqList.erase(nodeIt);
        }
    }
    
    string getMaxKey() {
        if (freqList.empty()) return "";
        return *freqList.back().keys.begin();
    }
    
    string getMinKey() {
        if (freqList.empty()) return "";
        return *freqList.front().keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */