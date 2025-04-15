class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string tok: tokens) {
            if(tok == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if(tok == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(tok == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else if(tok == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else st.push(stoi(tok));
        }
        return st.top();
    }
};