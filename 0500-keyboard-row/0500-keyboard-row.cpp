class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"}, res;
        for(string word: words) {
            vector<int> fre(3, 0);
            for(char ch: word) {
                ch = (char)tolower(ch);
                for(int i = 0; i < 3; i++) {
                    if(rows[i].contains(ch)) fre[i]++;
                }
            }
            if(fre[0] > 0) {
                if(fre[1] == 0 && fre[2] == 0) res.push_back(word);
            } else if(fre[1] > 0) {
                if(fre[0] == 0 && fre[2] == 0) res.push_back(word);
            } else if(fre[2] > 0) {
                if(fre[0] == 0 && fre[1] == 0) res.push_back(word);
            }
        }
        return res;
    }
};