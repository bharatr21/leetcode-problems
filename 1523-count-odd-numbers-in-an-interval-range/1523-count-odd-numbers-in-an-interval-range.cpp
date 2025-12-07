class Solution {
public:
    int countOdds(int low, int high) {
        int ln, hn;
        ln = (low + 1) / 2;
        hn = (high + 1) / 2;
        return (hn - ln + (high % 2));
    }
};