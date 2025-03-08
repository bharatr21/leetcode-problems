class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), nw = 0;
        int res = n;
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W') nw++;
        }
        res = min(nw, res);
        for(int i = k; i < n; i++) {
            if(blocks[i-k] == 'W') nw--;
            if(blocks[i] == 'W') nw++;
            res = min(nw, res);
        }
        return res;
    }
};