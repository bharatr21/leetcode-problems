class NumberContainers {
public:
    unordered_map<int, set<int>> nc;
    unordered_map<int, int> idxc;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int oldnum = idxc[index];
        nc[oldnum].erase(index);
        if(nc[oldnum].empty()) nc.erase(oldnum);
        nc[number].insert(index);
        idxc[index] = number;
    }
    
    int find(int number) {
        return (nc.count(number) ? *nc[number].begin() : -1);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */