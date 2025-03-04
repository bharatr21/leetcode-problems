class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, vector<pair<int, int>>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int key = (nums[i] + nums[j]) % d;
                mp[key].push_back({i, j});
            }
        }
        int res = 0;
        for(int k = 2; k < n; k++) {
            int search_key = (d - (nums[k] % d)) % d; 
            if(mp.count(search_key)) {
                for(auto item: mp[search_key]) {
                    if(k > item.second) res++; 
                }
            }
        }
        return res;
    }
};