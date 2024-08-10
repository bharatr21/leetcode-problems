class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        int n = s.size();
        unordered_set<int> remIdx;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(st.empty()) remIdx.insert(i); 
                else st.pop();
            }
        }
        while(!st.empty()) {
            int idx = st.top();
            st.pop();
            remIdx.insert(idx);
        }
        for(int i = 0; i < n; i++) {
            if(remIdx.count(i)) continue;
            else res += s[i];
        }
        return res;
    }
};