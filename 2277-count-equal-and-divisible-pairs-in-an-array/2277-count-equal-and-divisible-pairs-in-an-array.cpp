class Solution {
public:
    unordered_map<int, vector<int>> mp;
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        for(auto& el: mp) {
            if(el.second.size() >= 2) {
                int m = el.second.size();
                for(int i = 0; i < m; i++) {
                    for(int j = i + 1; j < m; j++) {
                        if((el.second[i] * el.second[j]) % k == 0) res++;
                    }
                }
            }
        }
        return res;
    }
};