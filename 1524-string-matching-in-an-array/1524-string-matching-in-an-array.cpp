class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> subs;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                if(words[i].find(words[j]) != string::npos) {
                    subs.insert(words[j]);
                }                
            }
        }
        vector<string> res(subs.begin(), subs.end());
        return res;
    }
};