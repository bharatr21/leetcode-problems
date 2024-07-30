class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), i;
        int res = n + 1;
        vector<int> act(n, 0), bct(n, 0);
        int ac = 0, bc = 0;
        for(i = 0; i < n; i++) {
            bct[i] = bc;
            if(s[i] == 'b') bc++;
        }
        for(i = n - 1; i >= 0; i--) {
            act[i] = ac;
            if(s[i] == 'a') ac++;
        }
        for(i = 0;i < n; i++) {
            res = min(res, act[i] + bct[i]);
        }
        return res;
    }
};