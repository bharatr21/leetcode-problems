class Solution {
public:
    void topo(queue<char>& q, string& res, vector<int>& vis, vector<int>& indeg, vector<vector<char>>& adj)
    {
        while(!q.empty())
        {
            char ch = q.front();
            q.pop();
            vis[(ch - 'a')] = 1;
            res += ch; 
            for(char c: adj[(ch - 'a')])
            {
                if(--indeg[(c - 'a')] == 0 && !vis[(c - 'a')]) q.push(c);
            }
        }
    }
    void buildDep(string a, string b, vector<int>& indeg, vector<vector<char>>& adj, bool& term)
    {
        int m = a.size(), n = b.size(), i;
        for(i = 0; i < min(m, n); i++)
        {
            if(a[i] != b[i])
            {
                indeg[(b[i] - 'a')]++;
                adj[(a[i] - 'a')].push_back(b[i]);
                term = false;
                return;
            }
        }
        if(m > n) term = true;
    }
    string alienOrder(vector<string>& words) {
        string res;
        vector<int> indeg(26, 0);
        vector<vector<char>> adj(26, vector<char>());
        set<char> seen;
        queue<char> q;
        vector<int> vis(26, 0);
        for(string word: words)
        {
            for(char ch: word)
            {
                seen.insert(ch);
            }
        }

        int n = words.size(), i;
        bool term = false;
        for(i = 0; i < n - 1; i++)
        {
            buildDep(words[i], words[i+1], indeg, adj, term);
            if(term) return "";
        }
        for(auto &ch: seen)
        {
            if(indeg[(ch - 'a')] == 0)
            {
                q.push(ch);
            }
        }
        topo(q, res, vis, indeg, adj);
        return ((res.size() == seen.size()) ? res: "");
    }
};