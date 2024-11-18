class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int res = 0, n = candies.size();
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(auto el: candies) {mp[el]++; st.insert(el);}
        if(k == 0) return st.size();
        for(int i = 0; i < k; i++) {
            if(--mp[candies[i]] == 0) st.erase(candies[i]);
        }
        res = max(res, (int)st.size());
        int sr = 0, en = k;
        while(en < n) {
            if(--mp[candies[en]] == 0) {
                st.erase(candies[en]);
            }
            if(!st.count(candies[sr]) || mp[candies[sr]] == 0) {
                st.insert(candies[sr]);
            }
            res = max(res, (int)st.size());
            en++;
            mp[candies[sr]]++;
            sr++;
        }
        // for(auto el: st) cout << el << ' ';
        // cout << endl;
        // cout << sr << ' ' << en << endl;
        return res;
    }
};