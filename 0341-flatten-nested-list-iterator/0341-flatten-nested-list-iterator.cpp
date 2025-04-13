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
    vector<int> flat;
    int cur;
    void flatten(vector<NestedInteger> &nestedList, vector<int>& flat) {
        for(NestedInteger ni: nestedList) {
            if(ni.isInteger()) flat.push_back(ni.getInteger());
            else {
                flatten(ni.getList(), flat);
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList, flat);
        cur = 0;
    }
    
    int next() {
        return flat[cur++];
    }
    
    bool hasNext() {
        return (cur < flat.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */