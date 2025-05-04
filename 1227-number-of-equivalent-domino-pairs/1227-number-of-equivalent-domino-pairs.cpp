class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size(), res = 0;
        map<pair<int, int>, int> mp;
        for(int i = 0; i < n; i++) {
            int a = dominoes[i][0], b = dominoes[i][1];
            int tmp = 0;
            if(mp.count({a, b})) tmp += mp[{a, b}];
            if(mp.count({b, a})) tmp += mp[{b, a}];
            res += (tmp / 2);
            if(a != b) {
                mp[{a, b}]++;
                mp[{b, a}]++;
            } else {
                mp[{a, a}]++;
            }
        }
        return res;
    }
};