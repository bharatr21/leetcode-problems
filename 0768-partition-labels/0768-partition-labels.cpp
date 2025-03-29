class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;
        vector<pair<int, int>> vp;
        int i = 0;
        for(char ch: s) {
            if(!mp.count(ch)) {
                mp[ch] = {i, i};
            }
            else {
                mp[ch].second = i;
            }
            i++;
        }
        for(auto& interval: mp) {
            vp.push_back(interval.second);
        }
        sort(vp.begin(), vp.end());
        // for(auto& el: vp) cout << "[" << el.first << "," << el.second << "]" << '\n';
        int n = vp.size();
        vector<pair<int, int>> pres;
        vector<int> res;
        pair<int, int> cur_interval = vp[0];
        for(int i = 1; i < n; i++) {
            auto [st, en] = vp[i];
            auto [cur_st, cur_en] = cur_interval;
            if(st > cur_en) {
                pres.push_back(cur_interval);
                cur_interval = vp[i];
            } else if(en < cur_st) {
                pres.push_back(vp[i]);   
            } else {
                cur_interval = {min(st, cur_st), max(en, cur_en)};
            }
        }
        pres.push_back(cur_interval);
        // cout << "\nMerged intervals: " << endl;
        // for(auto& el: pres) cout << "[" << el.first << "," << el.second << "]" << '\n';
        for(auto& pel: pres) {
            res.push_back(pel.second - pel.first + 1);
        }
        return res;
    }
};