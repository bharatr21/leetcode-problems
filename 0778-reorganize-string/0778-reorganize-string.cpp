class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string res;
        vector<int> fre(26, 0);
        priority_queue<vector<int>> pq;
        for(char ch: s) fre[ch - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(fre[i] > (n + 1)/2) return "";
            if(fre[i] > 0) pq.push(vector<int>{fre[i], i + 'a'});
        }
        while(!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            if(res.empty() || first[1] != res.back()) {
                res += (char)first[1];
                if(--first[0] > 0) pq.push(first);
            } else {
                if(pq.empty()) return "";
                auto sec = pq.top();
                pq.pop();
                res += (char)sec[1];
                if(--sec[0] > 0) pq.push(sec);
                pq.push(first);
            }
        }
        return res;
    }
};