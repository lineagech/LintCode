class Solution {
public:
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        // write your code here
        return dfs(nums);
    }
    bool dfs( vector<double>& nums )
    {
        int size = nums.size();
        if( size == 1 ) { //cout << (nums[0]-24.0) <<endl;
            return (fabs(nums[0]-24.0) < 1e-6); 
        }
        // pick two inside parenthesis
        for( int i = 0; i < size; i++ )
        {
            for( int j = 0; j < size; j++ )
            {
                if( i == j ) continue;
                
                vector<double> new_nums;
                for( int k = 0; k < size; k++ )
                    if( k != i && k != j ) new_nums.push_back(nums[k]);
                
                new_nums.emplace_back(0);
                if( i < j )
                {
                    new_nums[new_nums.size()-1] = nums[i]+nums[j] ;
                    if( dfs(new_nums) ) return true; 
                    
                    new_nums[new_nums.size()-1] = nums[i]*nums[j];
                    if( dfs(new_nums) ) return true; 
                }
                new_nums[new_nums.size()-1] = nums[i]/nums[j];
                if( dfs(new_nums) ) return true; 
                
                new_nums[new_nums.size()-1] = nums[i]-nums[j];
                if( dfs(new_nums) ) return true; 
            }
        }
        return false;
    }
};
