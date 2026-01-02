class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for(int el: nums) {
            if(s.count(el)) return el;
            s.insert(el);
        }
        return -1;
    }
};