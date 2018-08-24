class Solution {
public:
    /**
     * @param nums: an array
     * @return: the Next Greater Number for every element
     */
    vector<int> nextGreaterElements(vector<int> &nums) {
        // Write your code here
        vector<int> ans(nums.size(), -1);
        stack<pair<int,int>> stack;
        if( nums.size() == 0 ) return {};
        if( nums.size() == 1 ) { ans[0] = -1; return ans; }
        stack.push(make_pair(0,nums[0]));
        for( int i=1; i<nums.size(); i++)
        {
            while( !stack.empty() && nums[i] > stack.top().second )
            {   
                auto p = stack.top();
                stack.pop();
                ans[p.first] = nums[i];
            }
            stack.push(make_pair(i,nums[i]));
        }
        for( int i=0; i<nums.size(); i++ )
        {   
            if( i == stack.top().first ) break;
            while( nums[i] > stack.top().second )
            { 
                auto p = stack.top();
                stack.pop();
                ans[p.first] = nums[i];
            }
        }
        return ans;
    }
};
