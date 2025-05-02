class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> indices(n+2);
        vector<char> symbols(n+2);
        int cur = 1;
        indices[0] = -1;
        symbols[0] = 'L';
        for(int i = 0; i < n; i++) {
            if(dominoes[i] != '.') {
                indices[cur] = i;
                symbols[cur++] = dominoes[i];
            }
        }
        indices[cur] = n;
        symbols[cur++] = 'R';
        string res = dominoes;
        for(int idx = 0; idx < cur - 1; idx++) {
            int i = indices[idx], j = indices[idx+1];
            char x = symbols[idx], y = symbols[idx+1];
            if(x == y) {
                for(int k = i + 1; k < j; k++) {
                    res[k] = x;
                }
            } else if(x > y) {
                for(int k = i + 1; k < j; k++) {
                    res[k] = (k - i == j - k) ? '.' : ((k - i < j - k) ? 'R': 'L');
                }
            }
        }
        return res;
    }
};