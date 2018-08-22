class Solution {
public:
    /**
     * @param nums: 
     * @return: the maximum result of ai XOR aj, where 0 â‰¤ i, j < n
     */
    int findMaximumXOR(vector<int> &nums) {
        // Write your code here
        int res = 0;
        int mask = 0;
        for( int i = 31; i >= 0; i-- )
        {   
            unordered_set<int> set;
            mask |= ( 0x1 << i );
            for( auto n : nums ) set.insert( n&mask );
            
            int tmp = res | (0x1<<i);
            for( auto e : set )
            {
                if( set.count(e^tmp) )
                {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
     
};
