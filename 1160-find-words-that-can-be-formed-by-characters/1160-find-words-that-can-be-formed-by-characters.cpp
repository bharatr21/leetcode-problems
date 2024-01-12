class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> mp;
        for(char c: chars) mp[c]++;
        for(string word: words)
        {
            unordered_map<char, int> inmap;
            for(char c: word) inmap[c]++;
            int flag = 1;
            for(auto u: inmap)
            {
                if(mp.find(u.first) == mp.end() || u.second > mp[u.first])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans += word.size();
        }
        return ans;
    }
};