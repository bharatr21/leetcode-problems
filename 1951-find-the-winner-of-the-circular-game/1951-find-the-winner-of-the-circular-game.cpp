class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize vector of N friends, labeled from 1-N
        vector<int> circle;
        int i;
        for (i = 1; i <= n; i++) {
            circle.push_back(i);
        }
        i = 0;
        while(circle.size() > 1) {
            int cur = 1;
            i = (i + k - 1) % circle.size();
            circle.erase(circle.begin() + i);
        }
        return circle.front();
    }
};