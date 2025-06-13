class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
    DSU(int sz): parent(sz), rank(sz) {
        for(int i = 0; i < sz; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    void _union(int x, int y) {
        int xpar = findParent(x);
        int ypar = findParent(y);
        if(rank[xpar] > rank[ypar]) {
            parent[ypar] = xpar;
        } else if(rank[xpar] < rank[ypar]) {
            parent[xpar] = ypar;
        } else {
            parent[ypar] = xpar;
            rank[xpar]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailGroup;
        for(int i = 0; i < n; i++) {
            int m = accounts[i].size();
            string name = accounts[i][0];
            for(int j = 1; j < m; j++) {
                string email = accounts[i][j];
                if(emailGroup.count(email)) {
                    dsu._union(i, emailGroup[email]);
                } else emailGroup[email] = i;
            }
        }
        unordered_map<int, vector<string>> comps;
        for(auto emailItem: emailGroup) {
            auto [email, group] = emailItem;
            comps[dsu.findParent(group)].push_back(email);
        }
        for(auto compItem: comps) {
            int group = compItem.first;
            vector<string> comp = {accounts[group][0]};
            comp.insert(comp.end(), compItem.second.begin(), compItem.second.end());
            sort(comp.begin() + 1, comp.end());
            res.push_back(comp);
        }
        return res;
    }
};