class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(!small.empty()) {
            int el = small.top();
            if(num > el) large.push(num);
            else small.push(num);
        }
        else small.push(num);
        int ssz = small.size(), lsz = large.size();
        if(ssz - lsz > 1)
        {
            int el = small.top();
            small.pop();
            large.push(el);
        }
        else if(lsz - ssz > 1)
        {
            int el = large.top();
            large.pop();
            small.push(el);
        }
    }
    
    double findMedian() {
        int ssz = small.size(), lsz = large.size();
        if(ssz > lsz) return small.top();
        else if(lsz > ssz) return large.top();
        else return ((small.top() + large.top()) * 1.0) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */