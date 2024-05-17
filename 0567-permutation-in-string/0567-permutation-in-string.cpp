class Solution {
public:
    bool checkPerm(vector<int>& tmp, int idx, int sub_len, string s2) {
        int n = s2.size();
        if((n - idx) < sub_len) return false;
        int i = idx, ct = 0;
        while(i < n && ct < sub_len && tmp[s2[i] - 'a'] > 0)
        {
            tmp[s2[i] - 'a']--;
            i++;
            ct++;
        }
        return (ct == sub_len);
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26, 0);
        for(char c: s1) mp[c - 'a']++;
        int m = s1.size(), n = s2.size(), i;
        for(i = 0; i < n; i++)
        {
            if(mp[s2[i] - 'a'] > 0)
            {
                vector<int> tmp = mp;
                if(checkPerm(tmp, i, m, s2)) return true;
            }
        }
        return false;
    }
};