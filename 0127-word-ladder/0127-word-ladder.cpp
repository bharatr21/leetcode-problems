class Solution {
public:
    bool hasEdge(string w1, string w2, int n) {
        int diff = 0;
        for(int i = 0; i < n; i++) {
            if(w1[i] != w2[i]) diff++;
        }
        return (diff == 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        queue<pair<string, int>> q;
        unordered_set<string> seen; // Visited Set
        q.push({beginWord, 1});
        while(!q.empty()) {
            auto [curWord, depth] = q.front();
            q.pop();
            if(!seen.empty() && seen.count(curWord)) continue;
            if(curWord == endWord) return depth;
            seen.insert(curWord);
            for(string& word: wordList) {
                if(hasEdge(curWord, word, n) && !seen.count(word)) q.push({word, depth + 1}); 
            }
        }
        return 0;
    }
};