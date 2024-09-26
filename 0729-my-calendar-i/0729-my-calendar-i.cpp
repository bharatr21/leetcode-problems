class MyCalendar {
public:
    vector<pair<int, int>> times;
    bool isOverlap(pair<int, int> &i1, pair<int, int> &i2) {
        return !((i1.first >= i2.second) || (i2.first >= i1.second));
    }

    MyCalendar() {

    }
    
    bool book(int start, int end) {
        pair<int, int> new_time = {start, end};
        sort(times.begin(), times.end());
        for(auto time: times) {
            if(isOverlap(new_time, time)) return false;
        }
        times.push_back(new_time);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */