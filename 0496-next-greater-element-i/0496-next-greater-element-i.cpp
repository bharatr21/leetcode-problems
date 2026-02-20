class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> nge;
        stack<int> st;
        for(auto el: nums2) {
            while(!st.empty() && el > st.top()) {
                nge[st.top()] = el;
                st.pop();
            }
            st.push(el);
        }
        while(!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        transform(nums1.begin(), nums1.end(), back_inserter(res), [&nge](int x){return nge[x];});
        return res;
    }
};