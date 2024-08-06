class Solution {
public:
    static bool cmp(pair<char, int>& p1, pair<char, int>& p2) {
        return p1.second > p2.second;
    }
    int minimumPushes(string word) {
        int res = 0, ct = 7;
        unordered_map<char, int> cmap;
        for(char ch: word) cmap[ch]++;
        vector<pair<char, int>> vp(cmap.begin(), cmap.end());
        sort(vp.begin(), vp.end(), cmp);
        for(auto el: vp) {
            auto [ch, freq] = el;
            cout << ch << ' ' << freq << endl;
            ct++;
            res += (ct / 8) * freq;
        }
        return res;
    }
};