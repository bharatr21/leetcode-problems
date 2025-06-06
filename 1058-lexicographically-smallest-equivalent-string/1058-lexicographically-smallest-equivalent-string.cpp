class DSU {
    public:
        vector<int> repr;
    DSU() {
        repr.resize(26);
        for(int i = 0; i < 26; i++) repr[i] = i;
    }
    int find(int x) {
        if(repr[x] == x) return x;
        return repr[x] = find(repr[x]);
    }
    void _union(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(x < y) repr[y] = x;
        else repr[x] = y;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string res;
        int n = s1.size();
        DSU d;
        for(int i = 0; i < n; i++) {
            d._union(s1[i] - 'a', s2[i] - 'a');
        }
        for(char ch: baseStr) res += ('a' + d.find(ch - 'a'));
        return res;
    }
};