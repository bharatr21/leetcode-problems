class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        for(vector<string> regionq: regions) {
            int n = regionq.size();
            string par = regionq[0];
            for(int i = 1; i < n; i++) {
                parent[regionq[i]] = par;
            }
        }
        vector<string> path1, path2;
        path1.push_back(region1);
        path2.push_back(region2);
        string temp1 = region1, temp2 = region2;
        while(parent.count(temp1)) {
            temp1 = parent[temp1];
            path1.push_back(temp1);
        }
        while(parent.count(temp2)) {
            temp2 = parent[temp2];
            path2.push_back(temp2);
        }
        int m = path1.size(), n = path2.size();
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0 && path1[i] == path2[j]) {
                i--;
                j--;
        } 
        return path1[i+1];
    }
};