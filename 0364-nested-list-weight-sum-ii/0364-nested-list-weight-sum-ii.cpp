/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int getDepth(vector<NestedInteger>& nestedList, int depth) {
        int mx = depth;
        for(NestedInteger ni: nestedList) {
            if(!ni.isInteger()) {
                mx = max(mx, getDepth(ni.getList(), depth + 1));
            }
        }
        return mx;
    }
    
    int helper(vector<NestedInteger>& nestedList, int depth) {
        int res = 0;
        for(NestedInteger ni: nestedList) {
            if(ni.isInteger()) {
                res += ni.getInteger() * depth;
            }
            else res += helper(ni.getList(), depth - 1);
        }
        return res;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 1;
        int maxDepth = getDepth(nestedList, depth);
        return helper(nestedList, maxDepth);
    }
};