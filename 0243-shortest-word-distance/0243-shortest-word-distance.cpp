class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        unordered_map<string, vector<int>> idxMap;
        for(int i = 0; i < n; i++) {
            string word = wordsDict[i];
            idxMap[word].push_back(i);
        }
        int res = n + 1;
        auto v1 = idxMap[word1], v2 = idxMap[word2]; 
        int s1 = v1.size(), s2 = v2.size();
        if(s1 < s2) {
            for(int pos: v1) {
                int lb = lower_bound(v2.begin(), v2.end(), pos) - v2.begin();
                if(lb > 0) lb--;
                int ub = upper_bound(v2.begin(), v2.end(), pos) - v2.begin();
                cout << pos << ' ' << v2[lb] << ' ' << ((ub < s2) ? v2[ub]: '#');
                res = min(res, abs(pos - v2[lb]));
                if(ub < s2) res = min(res,  abs(v2[ub] - pos));
            }
            cout << endl;
        } else {
            for(int pos: v2) {
                int lb = lower_bound(v1.begin(), v1.end(), pos) - v1.begin();
                if(lb > 0) lb--;
                int ub = upper_bound(v1.begin(), v1.end(), pos) - v1.begin();
                cout << pos << ' ' << v1[lb] << ' ' << ((ub < s1) ? v1[ub] : '#');
                res = min(res, abs(pos - v1[lb]));
                if(ub < s1) res = min(res, abs(v1[ub] - pos));
            }
            cout << endl;
        }
        return res;
    }
};