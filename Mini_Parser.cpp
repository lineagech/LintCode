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
    NestedInteger deserialize(string s) {
        int idx = 0;
        return _deserialize(s, idx);
    }
    NestedInteger _deserialize(string s, int& idx) 
    {    
        NestedInteger curr;
        while( true )
        {   
            int value = 0;
            int digit_count = 0;
            bool neg = false;
            if( s[idx] == '[' ) idx++;
            if( s[idx] == '-' ){
                neg = true;
                idx++;
            }
            while( isdigit(s[idx]) ) {
                value = value*10 + (s[idx]-'0');
                idx++;
                digit_count++;
            }
            if( idx == s.size() || s[idx] == ']') {
                if(digit_count > 0) {
                    curr.setInteger((neg)?-value:value);
                    if(s[idx] == ']') curr.add(curr);
                }
                return curr;
            }
            else
            {
                NestedInteger tmp;
                if(digit_count > 0) 
                {
                    tmp.setInteger((neg)?-value:value);
                    curr.add(tmp);
                }
            }
            if( s[idx] == ',' ) idx++;
            if( s[idx] == '[' )
            {
                NestedInteger next = _deserialize(s, idx);
                curr.add(next);
                idx++;
            }
            if(s[idx] == ']') return curr;
        }
        
    }
};
