class Solution {
public:
    bool balanced(int n) {
        int tmp = n;
        vector<int> fre(10, 0);
        while(tmp) {
            fre[tmp % 10]++;
            tmp = tmp / 10;
        }
        bool nb = true;
        if(fre[0] != 0) nb = false;
        for(int i = 1; i < 10 && nb; i++) {
            if(fre[i] == 0) continue;
            if(fre[i] != i) {nb = false; break;} 
        }
        return nb;
    }
    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i <= 1224445; i++) {
            if(balanced(i)) return i;
        }
        return 1;
    }
};