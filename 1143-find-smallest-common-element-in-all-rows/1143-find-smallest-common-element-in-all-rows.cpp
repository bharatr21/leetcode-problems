class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, int> mp;
        for(auto row: mat) {
            for(int el: row) mp[el]++;
        }
        for(auto u: mp) {
            if(u.second == m) return u.first;
        }
        return -1;
    }
};