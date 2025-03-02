class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> store;
        for(auto item: nums1) {
            int id = item[0], score = item[1];
            store[id] = score;
        }
        for(auto item: nums2) {
            int id = item[0], score = item[1];
            if(store.count(id)) store[id] += score;
            else store[id] = score;
        }
        vector<vector<int>> res;
        for(auto u: store) res.push_back({u.first, u.second});
        return res;
    }
};