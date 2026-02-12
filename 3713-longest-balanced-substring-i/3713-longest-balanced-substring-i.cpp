class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int, int> dis;
        vector<int> fre(26);
        int res = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            fill(fre.begin(), fre.end(), 0);
            for(int j = i; j < n; j++) {
                bool flag = true;
                fre[s[j] - 'a']++;
                for(auto& el: fre) {
                    if(el > 0 && el != fre[s[j] - 'a']) {
                        flag = false;
                        break;
                    }
                }
                if(flag) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};