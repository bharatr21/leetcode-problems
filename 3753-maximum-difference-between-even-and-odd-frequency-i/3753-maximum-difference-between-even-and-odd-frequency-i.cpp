class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> fre(26, 0);
        for(char ch: s) fre[ch - 'a']++;
        int emn = n + 1, omx = 0;
        for(int i = 0; i < 26; i++) {
            if(fre[i] % 2) omx = max(omx, fre[i]);
            else if(fre[i] > 0) emn = min(emn, fre[i]);
        }
        return omx - emn;
    }
};