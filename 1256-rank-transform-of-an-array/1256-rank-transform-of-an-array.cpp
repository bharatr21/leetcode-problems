class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        map<int, vector<int>> mp;
        for(int i = 0 ; i < n; i++) mp[arr[i]].push_back(i);
        int rank = 1;
        for(auto u: mp) {
            for(auto el: u.second) {
                res[el] = rank;
            }
            rank++;
        }
        return res;
    }
};