/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> st;
        int cand = 0, cur = 1;
        while(cur < n) {
            if(knows(cand, cur)) {
                st.insert(cand);
                cand = cur;
            } else {
                st.insert(cur);
            }
            cur++;
        }
        for(auto u: st) {
            if(knows(cand, u) || !knows(u, cand)) return -1;
        }
        return cand;
    }
};