class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(), i, j;
        vector<int> prev(m+1, 0); 
        for(j = n-1; j >= 0; j--)
        {
            vector<int> cur(m+1, 0);
            for(i = m-1; i >= 0; i--)
            {
                if(text1[i] == text2[j]) {cur[i] = 1 + prev[i+1];}
                else cur[i] = max(cur[i+1], prev[i]);
            }
            prev = cur;
        }
        return prev[0];
    }
};
