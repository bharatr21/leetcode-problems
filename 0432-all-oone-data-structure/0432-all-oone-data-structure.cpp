class Node {
    public:
        int freq;
        Node* prev;
        Node* next;
        unordered_set<string> keys;
        Node(int val): freq(val), prev(NULL), next(NULL) {}
};

class AllOne {
public:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> mp;
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(mp.count(key)) {
            Node* node = mp[key];
            int freq = node->freq;
            node->keys.erase(key);
            Node* nextNode = node->next;
            if(nextNode == tail || nextNode->freq != freq + 1) {
                Node* temp = new Node(freq + 1);
                temp->keys.insert(key);
                temp->prev = node;
                temp->next = nextNode;
                node->next = temp;
                nextNode->prev = temp;
                mp[key] = temp;
            } else {
                nextNode->keys.insert(key);
                mp[key] = nextNode;
            }
            if(node->keys.empty()) removeNode(node);
        } else {
            Node* first = head->next;
            if(first == tail || first->freq > 1) {
                Node* temp = new Node(1);
                temp->keys.insert(key);
                temp->prev = head;
                temp->next = first;
                head->next = temp;
                first->prev = temp;
                mp[key] = temp;
            } else {
                first->keys.insert(key);
                mp[key] = first;
            }
        }
    }
    
    void dec(string key) {
        if(!mp.count(key)) return;
        Node* node = mp[key];
        int freq = node->freq;
        node->keys.erase(key);
        if(freq == 1) mp.erase(key);
        else {
            Node* prevNode = node->prev;
            if(prevNode == head || prevNode->freq != freq - 1) {
                Node* temp = new Node(freq - 1);
                temp->keys.insert(key);
                temp->prev = prevNode;
                temp->next = node;
                prevNode->next = temp;
                node->prev = temp;
                mp[key] = temp;
            } else {
                prevNode->keys.insert(key);
                mp[key] = prevNode;
            }
        }
        if(node->keys.empty()) removeNode(node);
    }
    
    string getMaxKey() {
        return ((tail->prev == head) ? "" : *(tail->prev->keys.begin()));   
    }
    
    string getMinKey() {
        return ((head->next == tail) ? "" : *(head->next->keys.begin()));
    }

private:
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;  // Link previous node to next node
        nextNode->prev = prevNode;  // Link next node to previous node

        delete node;  // Free the memory of the removed node
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