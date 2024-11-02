class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        int n = words.size();
        int nsz = words[n-1].size();
        if(words[0][0] != words[n-1][nsz - 1]) return false;
        for(int i = 1; i < n; i++) {
            if(words[i][0] != words[i-1][words[i-1].size() - 1]) return false;
        }
        return true;
    }
};