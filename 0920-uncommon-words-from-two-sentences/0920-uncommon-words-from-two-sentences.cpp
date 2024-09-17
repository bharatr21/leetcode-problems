class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> sm1, sm2;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string token;
        char delim = ' ';
        vector<string> tokens1, tokens2, res;
        while(getline(ss1, token, delim)) {
            tokens1.push_back(token);
            sm1[token]++;
        }
        while(getline(ss2, token, delim)) {
            tokens2.push_back(token);
            sm2[token]++;
        }
        for(auto u: sm1) {
            if(!sm2.count(u.first) && u.second == 1) {
                res.push_back(u.first);
            } 
        }
        for(auto u: sm2) {
            if(!sm1.count(u.first) && u.second == 1) {
                res.push_back(u.first);
            } 
        }
        return res;
    }
};