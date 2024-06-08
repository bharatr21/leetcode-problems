class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(), i;
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        st.push({temperatures[0], 0});
        for(i = 1; i < n; i++)
        {
            while(!st.empty() && st.top().first < temperatures[i])
            {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};