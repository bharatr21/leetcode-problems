class Solution {
public:
    int equalDigitFrequency(string s) {
        int res = 0, n = s.size();
        unordered_set<string> subs;
        for(int i = 0; i < n; i++) {
            vector<int> dfreq(10, 0);
            for(int j = i; j < n; j++) {
                dfreq[s[j] - '0']++;
                int commonfreq = 0;
                bool isValid = true;
                for(int k = 0; k < dfreq.size(); k++) {
                    if(dfreq[k] == 0) continue;
                    if(commonfreq == 0) commonfreq = dfreq[k];
                    if(commonfreq != dfreq[k]) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) {
                    string tmp = s.substr(i, j - i + 1);
                    subs.insert(tmp);
                }
            }
        }
        return subs.size();
    }
};