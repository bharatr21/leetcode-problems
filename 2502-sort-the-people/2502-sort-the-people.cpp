class Solution {
public:
    static bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
        return (p1.second > p2.second);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> res;
        int n = names.size(), i;
        vector<pair<string, int>> vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({names[i], heights[i]});
        }
        sort(vp.begin(), vp.end(), cmp);
        for(auto el: vp) {
            res.push_back(el.first);
        }
        return res;
    }
};