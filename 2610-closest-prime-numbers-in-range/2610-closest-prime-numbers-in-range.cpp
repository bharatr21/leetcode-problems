class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        array<bool, 1000001> vis;
        vis.fill(true);
        vis[0] = false;
        vis[1] = false;
        for(int i = 2; i * i <= 1000000; i++) {
            if(vis[i]) {
                primes.push_back(i);
                for(int j = i * i; j <= 1000000; j += i) {
                    vis[j] = false;
                }
            }
        }
        vector<int> cand, res = {-1, -1};
        for(int i = left; i <= right; i++) {
            if(vis[i]) cand.push_back(i);
        }
        if(cand.size() >= 2) {
            int n = cand.size(), gap = 1000001;
            for(int i = 0; i < n - 1; i++) {
                if(gap > cand[i+1] - cand[i]) {
                    gap = cand[i+1] - cand[i];
                    res = {cand[i], cand[i+1]};
                }
            }
        }
        return res;
    }
};