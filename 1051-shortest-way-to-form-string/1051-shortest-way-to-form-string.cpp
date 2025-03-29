class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> spos, tpos;
        int m = source.size(), n = target.size();
        for(int i = 0; i < m; i++) spos[source[i]].push_back(i);
        for(int i = 0; i < n; i++) tpos[target[i]].push_back(i);
        for(auto& item: tpos) {
            if(!spos.count(item.first)) return -1;
        }
        int cur_idx = -1, res = 1;
        for(char ch: target) {
            // cout << "Character: " << ch << " Index: " << cur_idx << endl;
            auto it = upper_bound(spos[ch].begin(), spos[ch].end(), cur_idx);
            if(it == spos[ch].end()) {
                res++;
                it = spos[ch].begin();
            }
            cur_idx = *it;
        }
        return res;
    }
};