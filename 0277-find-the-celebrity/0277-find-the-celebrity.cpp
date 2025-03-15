/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0;
        for(int i = 0; i < n; i++) {
            if(knows(cand, i)) {
                cand = i;
            }
        }
        return (isCeleb(cand, n) ? cand : -1);
    }
    bool isCeleb(int cand, int n) {
        for(int i = 0; i < n; i++) {
            if(i == cand) continue;
            if(knows(cand, i) || !knows(i, cand)) return false;
        }
        return true;
    }
};