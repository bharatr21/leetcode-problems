class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int ballsleft = 0, movesleft = 0, ballsright = 0, movesright = 0;
        vector<int> answer(n, 0);
        for(int i = 0; i < n; i++) {
            answer[i] += movesleft;
            ballsleft += (boxes[i] - '0');
            movesleft += ballsleft;

            int j = n - 1 - i;
            answer[j] += movesright;
            ballsright += (boxes[j] - '0');
            movesright += ballsright;
        }
        return answer;
    }
};