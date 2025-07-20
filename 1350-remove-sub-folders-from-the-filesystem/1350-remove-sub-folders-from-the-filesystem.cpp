class Solution {
public:
    bool isSubfolder(string s, string pat) {
        return !(s.find(pat));
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string> res;
        sort(folder.begin(), folder.end());
        res.push_back(folder[0]);
        for(int i = 1; i < n; i++) {
            string last = res.back();
            last += '/';
            if(!isSubfolder(folder[i], last)) res.push_back(folder[i]);
        }
        return res;
    }
};