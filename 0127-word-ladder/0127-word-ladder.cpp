class Solution {
public:
    bool diff(string s1, string s2) {
        int n = s1.size(), res = 0;
        if(s2.size() != n) return false;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) res++;
        }
        return (res == 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> vis;
        q.push({beginWord, 1});
        while(!q.empty()) {
            auto [curWord, level] = q.front();
            q.pop();
            if(curWord == endWord) return level;
            if(vis.count(curWord)) continue;
            vis.insert(curWord);
            for(string word: wordList) {
                if(diff(curWord, word)) q.push({word, level + 1});
            }
        }
        return 0;
    }
};