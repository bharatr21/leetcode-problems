class Solution {
public:
    bool isAdjacent(string word1, string word2) {
        int n = word1.size(), res = 0;
        for(int i = 0; i < n; i++) {
            res += (word1[i] != word2[i]);
        }
        return (res == 1);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, vector<string>> adj;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string w1 = wordList[i], w2 = wordList[j];
                if(isAdjacent(w1, w2)) {
                    adj[w1].push_back(w2);
                    adj[w2].push_back(w1);
                }
            }
        }
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            for(int i = 0; i < n; i++) {
                string w = wordList[i];
                if(isAdjacent(beginWord, w)) adj[beginWord].push_back(w);
            }
        }
        
        unordered_set<string> seen;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()) {
            auto [word, depth] = q.front();
            q.pop();
            if(seen.count(word)) continue;
            seen.insert(word);
            for(string nextWord: adj[word]) {
                if(nextWord == endWord) return (depth + 1);
                q.push({nextWord, depth + 1});
            }
        }
        return 0;
    }
};