class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
            else st.push(i);
        }
        return ans;
    }
};