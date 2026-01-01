class Leaderboard {
public:
    unordered_map<int, int> scores;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(scores.count(playerId)) scores[playerId] += score;
        else scores[playerId] = score;

    }
    
    int top(int K) {
        int res = 0;
        for(auto& el: scores) {
            pq.push({el.second, el.first});
            if(pq.size() > K) pq.pop();
        }
        while(!pq.empty()) {
            res += pq.top().first;
            pq.pop();
        }
        return res;
        
    }
    
    void reset(int playerId) {
        scores[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */