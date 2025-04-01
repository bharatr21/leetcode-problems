class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        set<tuple<int, string, string>> vis;
        map<tuple<string, string, string>, int> pattern;
        set<tuple<string, string, string, string>> store;
        unordered_map<string, vector<string>> hist;
        int n = username.size();
        for(int i = 0; i < n; i++) {
            vis.insert({timestamp[i], username[i], website[i]});
        }
        for(auto& el: vis) {
            auto [timestamp, user, website] = el;
            hist[user].push_back(website);
        }
        for(auto& h: hist) {
            auto [user, websites] = h;
            int n = websites.size();
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    for(int k = j + 1; k < n; k++) {
                        if(!store.count({user, websites[i], websites[j], websites[k]})) {
                            pattern[{websites[i], websites[j], websites[k]}]++;
                            store.insert({user, websites[i], websites[j], websites[k]});
                        }
                    }
                }
            }
        }
        int mx = -1;
        tuple<string, string, string> tmp;
        for(auto& pat: pattern) {
            if(pat.second > mx) {
                mx = pat.second;
                tmp = pat.first;
            }
        }
        auto [s1, s2, s3] = tmp;
        vector<string> res = {s1, s2, s3};
        return res;
    }
};