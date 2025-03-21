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
    int findMaxDepth(int depth, vector<NestedInteger>& nestedList) {
        int res = depth;
        for(auto ni: nestedList) {
            if(!ni.isInteger()) {
                res = max(res, findMaxDepth(depth + 1, ni.getList()));
            }
        }
        return res;
    }

    int depthSum(int maxDepth, int depth, vector<NestedInteger>& nestedList) {
        int res = 0;
        for(auto ni: nestedList) {
            if(ni.isInteger()) {
                res += ni.getInteger() * (maxDepth - depth + 1);
            } else {
                res += depthSum(maxDepth, depth + 1, ni.getList());
            }
        }
        return res;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = findMaxDepth(1, nestedList);
        return depthSum(maxDepth, 1, nestedList);
    }
};