class AuthenticationManager {
public:
    unordered_map<string, int> tokens;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }

    void expire(int currentTime) {
        for(auto it = tokens.begin(); it != tokens.end();) {
            if(currentTime >= it->second) it = tokens.erase(it);
            else it++;
        }
    }
    
    void renew(string tokenId, int currentTime) {
        expire(currentTime);
        if(tokens.count(tokenId)) tokens[tokenId] = currentTime + ttl;
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