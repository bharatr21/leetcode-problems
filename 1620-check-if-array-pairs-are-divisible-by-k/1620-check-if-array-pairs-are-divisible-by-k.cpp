class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int el: arr) mp[(el % k + k) % k]++;
        if(mp[0] % 2) return false;
        for(int i = 1; i <= k/2; i++) {
            if(mp[i] != mp[k - i]) return false;
        }
        return true;
    }
};