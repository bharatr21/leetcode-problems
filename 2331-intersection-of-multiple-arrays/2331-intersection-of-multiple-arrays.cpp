class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> res;
        int m = nums.size();
        unordered_map<int, int> mp;
        for(vector<int> v: nums) {
            for(int el: v) {
                mp[el]++;
            }
        }
        for(auto u: mp) {
            if(u.second == m) res.push_back(u.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};