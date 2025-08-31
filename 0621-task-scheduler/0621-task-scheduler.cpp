class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int> mp;
        for(char ch: tasks) {
            mp[ch]++;
        }
        // vector<pair<char, int>> vp;
        int mx = 0, ct = 0;
        for(auto el: mp) {
            // vp.push_back({el.second, el.first});
            mx = max(mx, el.second);
        }
        for(auto el: mp) {
            if(el.second == mx) ct++;
        }
        return max(((mx - 1) * (n + 1) + ct), m); 
        // sort(vp.begin(), vp.end(), greater<pair<char, int>>());
    }
};