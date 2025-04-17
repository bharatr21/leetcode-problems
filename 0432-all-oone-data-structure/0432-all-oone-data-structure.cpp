class AllOne {
public:
    struct Node {
        int freq;
        unordered_set<string> keys;
    };
    list<Node> freqList;
    unordered_map<string, list<Node>::iterator> key2it;
    AllOne() {
        
    }
    
    void inc(string key) {
        auto nodeIt = key2it.count(key) ? key2it[key] : 
        freqList.insert(freqList.begin(), Node{0, {}});
        int f = nodeIt->freq;
        auto nextNode = next(nodeIt);
        if(nextNode == freqList.end() || nextNode->freq != f + 1) {
            nextNode = freqList.insert(nextNode, Node{f + 1, {}});
        }
        nextNode->keys.insert(key);
        key2it[key] = nextNode;

        nodeIt->keys.erase(key);
        if(nodeIt->keys.empty()) freqList.erase(nodeIt);
    }
    
    void dec(string key) {
        auto mapIt = key2it.find(key);
        if(mapIt == key2it.end()) return;
        auto nodeIt = mapIt->second;
        int f = nodeIt->freq;
        if(f > 1) {
            auto pre = (nodeIt == freqList.begin()) ? freqList.end(): prev(nodeIt);

            if(pre == freqList.end() || pre->freq != f - 1) {
                pre = freqList.insert(nodeIt, Node{f - 1, {}});
            }
            pre->keys.insert(key);
            key2it[key] = pre;
        } else {
            key2it.erase(mapIt);
        }
        nodeIt->keys.erase(key);
        if(nodeIt->keys.empty()) freqList.erase(nodeIt);
    }
    
    string getMaxKey() {
        if (freqList.empty()) return "";
        return *(freqList.back().keys.begin());
    }
    
    string getMinKey() {
        if (freqList.empty()) return "";
        return *(freqList.front().keys.begin());
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