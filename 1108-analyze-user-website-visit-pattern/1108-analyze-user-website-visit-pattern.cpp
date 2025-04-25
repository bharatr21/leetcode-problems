class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size(), mx = -1;
        vector<string> res;
        vector<tuple<int, string, string>> logs;
        unordered_map<string, vector<string>> hist;
        map<vector<string>, int> hits;
        set<tuple<string, string, string>> seen;
        for(int i = 0; i < n; i++) {
            logs.push_back({timestamp[i], username[i], website[i]});
        }
        sort(logs.begin(), logs.end());
        for(auto& item: logs) {
            auto [timestamp, user, site] = item;
            hist[user].push_back(site);
        }
        for(auto& item: hist) {
            string user = item.first;
            vector<string> sites = item.second;
            int m = hist[user].size();
            seen.clear();
            if(m < 3) continue;
            for(int i = 0; i < m; i++) {
                for(int j = i + 1; j < m; j++) {
                    for(int k = j + 1; k < m; k++) {
                        string site1 = sites[i], site2 = sites[j], site3 = sites[k];
                        if(!seen.count({site1, site2, site3})) {
                            hits[{site1, site2, site3}]++;
                            seen.insert({site1, site2, site3});
                        }
                    }
                }
            }
        }
        for(auto& item: hits) {
            if(mx < item.second) {
                mx = item.second;
                res = item.first;
            }
        }
        return res;
    }
};