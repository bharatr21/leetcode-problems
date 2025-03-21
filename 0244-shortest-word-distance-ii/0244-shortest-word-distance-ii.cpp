class WordDistance {
public:
    unordered_map<string, vector<int>> mp;
    int n;
    WordDistance(vector<string>& wordsDict) {
        int i = 0;
        n = wordsDict.size();
        for(string word: wordsDict) {
            mp[word].push_back(i++);
        }
    }
    
    int shortest(string word1, string word2) {
        int mn = n + 1, i = 0, j = 0;
        vector<int> w1 = mp[word1], w2 = mp[word2];
        int s1 = w1.size(), s2 = w2.size();
        while(i < s1 && j < s2) {
            mn = min(mn, abs(w1[i] - w2[j]));
            if(w1[i] < w2[j]) i++;
            else j++;
        }
        return mn;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */