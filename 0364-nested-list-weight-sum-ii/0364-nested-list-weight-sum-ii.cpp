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
    int maxDepth(vector<NestedInteger>& nestedList, int depth, int mxd) {
        mxd = max(depth, mxd);
        for(auto el: nestedList) {
            if(!el.isInteger()) {
                if(el.getList().size()) {
                    mxd = maxDepth(el.getList(), depth+1, mxd);
                }
            }
        }
        return mxd;
    }

    int depthHelper(vector<NestedInteger>& nestedList, int depth, int maxDepth) {
        int tot = 0;
        for(auto el: nestedList) {
            if(el.isInteger()) {
                tot += el.getInteger() * (maxDepth - depth + 1);
            }
            tot += depthHelper(el.getList(), depth+1, maxDepth);
        }
        return tot;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int mxd = maxDepth(nestedList, 1, 1);
        return depthHelper(nestedList, 1, mxd);
    }
};