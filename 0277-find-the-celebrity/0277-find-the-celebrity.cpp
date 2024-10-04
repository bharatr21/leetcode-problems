/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0, cur = 1;
        while(cur < n) {
            if(knows(cand, cur)) {
                cand = cur;
            }
            cur++;
        }
        for(int i = 0; i < n; i++) {
            if(i != cand)
            if(knows(cand, i) || !knows(i, cand)) return -1;
        }
        return cand;
    }
};