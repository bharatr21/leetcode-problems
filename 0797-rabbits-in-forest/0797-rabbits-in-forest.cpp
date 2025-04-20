class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> fre(1000, 0);
        for(int el: answers) fre[el]++;
        int res = 0;
        for(int k = 0; k < 1000; k++) res += fre[k] + 
        ((-fre[k]) % (k + 1) + (k + 1)) % (k + 1);
        return res;
    }
};