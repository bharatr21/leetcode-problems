class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<int> count(n);
        for(int i = 0; i < n; i++) {
            if(i == 0 || s[i] != s[i-1]) count[i] = 1;
            else count[i] = count[i-1] + 1;
            if(count[i] == k) {
                s.erase(i-k+1, k);
                i = i - k;
            }            
        }
        return s;
    }
};