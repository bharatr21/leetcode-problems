class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int net_shift = 0;
        int n = s.size();
        string res = s;
        for(vector<int> v: shift) {
            if(v[0] == 0) net_shift -= v[1];
            else net_shift += v[1];
        }
        if(net_shift < 0) net_shift = (net_shift % n + n) % n;
        while(net_shift--) {
            char ch = res[n - 1];
            res.pop_back();
            res = ch + res;
        }
        return res;
    }
};