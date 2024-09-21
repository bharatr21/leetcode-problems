class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> tmp;
        vector<int> res;
        for(int i = 1; i <= n; i++) tmp.push_back(to_string(i));
        sort(tmp.begin(), tmp.end());
        for(auto el: tmp) res.push_back(stoi(el));
        return res;
    }
};