class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, m = prerequisites.size(), i, j;
        queue<int> q;
        vector<vector<int>> adj(n , vector<int>());
        int vis = 0;
        vector<int> indeg(n, 0);
        for(i = 0; i < m; i++)
        {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        for(i = 0; i < n; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            vis++;
            for(int v: adj[u])
            {
                if(--indeg[v] == 0) q.push(v);
            }
        }
        return vis == numCourses;
    }
};