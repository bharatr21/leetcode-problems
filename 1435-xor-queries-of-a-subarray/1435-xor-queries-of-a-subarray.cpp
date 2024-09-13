class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        int n = arr.size();
        vector<int> pre(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] ^ arr[i-1];
        }
        for(vector<int> q: queries) {
            int st = q[0], en = q[1];
            res.push_back(pre[st] ^ pre[en+1]);
        }
        return res;
    }
};