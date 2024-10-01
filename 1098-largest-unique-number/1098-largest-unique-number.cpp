class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> mp;
        for(int el: nums) mp[el]++;
        for(auto it = mp.rbegin(); it != mp.rend(); it++) {
            auto val = *it;
            if(val.second == 1) return val.first;
        }
        return -1;
    }
};