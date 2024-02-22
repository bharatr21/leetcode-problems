class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judge(n + 1, 1);
        vector<int> indeg(n + 1, 0);
        for(vector<int> v: trust)
        {
            int a = v[0], b = v[1];
            indeg[b]++;
            judge[a] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            if(judge[i] == 1 && indeg[i] == n - 1) return i;
        }
        return -1;
    }
};