class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> mp;
        for(int el: nums) mp[el]++;
        for(auto it = mp.rbegin(); it != mp.rend(); it++) {
            if(it->second == 1) return it->first;
        }
        return -1;
    }
};