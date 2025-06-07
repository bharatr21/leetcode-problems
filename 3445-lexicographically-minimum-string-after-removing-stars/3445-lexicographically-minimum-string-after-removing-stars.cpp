class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> fre(26);
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') fre[s[i] - 'a'].push(i);
            else {
                for(int j = 0; j < 26; j++) {
                    if(!fre[j].empty()) {
                        s[fre[j].top()] = '*';
                        fre[j].pop();
                        break;
                    }
                }
            }
        }
        string res;
        for(char ch: s) {
            if(ch != '*') res.push_back(ch);
        }
        return res;
    }
};