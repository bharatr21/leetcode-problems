class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(i == 0 || s[i] != s[i-1]) st.push(1);
            else if(++st.top() == k) {
                s.erase(i-k+1, k);
                st.pop();
                i = i - k;
            }
        }
        return s;
    }
};