class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int unb = 0;
        for(char ch: s) {
            if(ch == '[') st.push(ch);
            else {
                if(!st.empty()) st.pop();
                else unb++;
            }
        }
        return (unb + 1) / 2;
    }
};