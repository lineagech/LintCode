class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int max_num = INT_MIN;
        unordered_map<int,int> occasions;
        unordered_map<int,int> opts;
        
        for( int i=0; i<nums.size(); i++ ) {
            occasions[nums[i]]++;
            max_num = (max_num < nums[i]) ? nums[i] : max_num;
        }
        for( int i=0; i<nums.size(); i++ )
        {   
            if( occasions[nums[i]] > opts[nums[i]] )
            {
                occasions[nums[i]]--;
                
                if( nums[i]+1 <= max_num && occasions[nums[i]+1] > 0 ) occasions[nums[i]+1]--;
                else return false;
                
                if( nums[i]+2 <= max_num && occasions[nums[i]+2] > 0 ) occasions[nums[i]+2]--;
                else return false;
                
                opts[nums[i]+3]++;
            }
            else
            {   
                if( occasions[nums[i]] > 0 )
                {
                    occasions[nums[i]]--; 
                    opts[nums[i]]--;
                    opts[nums[i]+1]++;
                }
            }
        }
        for( int i=0; i<nums.size(); i++ )
            if( occasions[nums[i]] != 0 ) return false;
        
        return true;
    }
};
