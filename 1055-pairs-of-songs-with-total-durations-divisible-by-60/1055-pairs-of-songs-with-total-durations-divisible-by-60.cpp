class Solution {
public:
    long long int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        long long int res = 0;
        for(int t: time) mp[t % 60]++;
        if(mp.count(0)) res += (1LL * mp[0] * (mp[0] - 1)) / 2; 
        if(mp.count(30)) res += (mp[30] * (mp[30] - 1)) / 2; 
        for(int i = 1; i <= 29; i++) {
            if(mp.count(i) && mp.count(60 - i)) res += mp[i] * mp[60 - i];
        }
        return res;
    }
};