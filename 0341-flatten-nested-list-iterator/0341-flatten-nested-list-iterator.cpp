/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flattened;
    int pos;

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        pos = 0;
    }

    void flatten(vector<NestedInteger> &nestedList) {
        for(NestedInteger ni: nestedList) {
            if(ni.isInteger()) flattened.push_back(ni.getInteger());
            else flatten(ni.getList());
        }
    }
    
    int next() {
        return flattened[pos++];
    }
    
    bool hasNext() {
        return (pos < flattened.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */