class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> tokens;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void expire(int currentTime) {
        for(auto it = tokens.begin(); it != tokens.end(); ) {
            auto [token, time] = *it;
            if(time <= currentTime - ttl) {
                it = tokens.erase(it);
            } else it++;
        }
    }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        expire(currentTime);
        if(tokens.count(tokenId)) tokens[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        expire(currentTime);
        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */