/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<NestedInteger> list(nestedList);
        vector<NestedInteger> next;
        bool isFlat = true;
        while( isFlat )
        {   
            isFlat = false;
            for( auto ni : list )
            {
                if( ni.isInteger() ) next.push_back(ni);
                else {
                    isFlat = true;
                    vector<NestedInteger> tmp = ni.getList();
                    for( auto sub_ni : tmp ) next.push_back(sub_ni);
                }
            }
            list = next;
            next.clear();
        }
        vector<int> ans;
        for( auto ni : list ) ans.push_back(ni.getInteger());
        return ans;
    }
};
