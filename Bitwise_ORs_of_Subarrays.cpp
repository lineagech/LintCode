class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        if( n == 0 ) return 0;
        unordered_set<int> curr;
        unordered_set<int> ans;
        for( auto num : A )
        {   
            unordered_set<int> next;
            for( auto c : curr )
            {
                if( next.find(c|num) == next.end() )
                    next.insert( c | num );
            }
            if( next.find(num) == next.end() )
                next.insert(num);
            curr = next;
            ans.insert(curr.begin(), curr.end());
        }
        
        return ans.size();
    }
};
