class Solution {
public:
    /**
     * @param nums: a sorted array
     * @param a: 
     * @param b: 
     * @param c: 
     * @return: a sorted array
     */
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        // Write your code here
        // ax^2+bx+c = a(x+b/2a)^2 + c-b^2/4a
        vector<int> ans(nums.size());
        if(a == 0) 
        {
            if(b >= 0) 
                for(int i=0; i<nums.size(); i++) ans[i] = b*nums[i]+c;
            else 
                for(int i=nums.size()-1; i>=0; i--) ans[nums.size()-1-i] = b*nums[i]+c;
        }
        else if(a > 0)
        {
            // has minimum at -b/2a
            double cen = -(double)b/(double)(2*a); 
            // find the most cloest two points
            auto it = upper_bound(nums.begin(), nums.end(), (int)cen);
            int left = (it == nums.begin()) ? 0 : it-nums.begin()-1;
            int right = left+1;
            for(int i=0; i<nums.size(); i++)
            {
                if( left>=0 && left<nums.size() && right>=0 && right<nums.size())
                {
                    if(fabs((double)nums[left]-cen)<fabs((double)nums[right]-cen) )
                        ans[i] = get_value(a, b, c, nums[left--]); 
                    else
                        ans[i] = get_value(a, b, c, nums[right++]);
                    
                }
                else if(left < 0) 
                    ans[i] = get_value(a, b, c, nums[right++]);
                else if(right >= nums.size())
                    ans[i] = get_value(a, b, c, nums[left--]);
            }
            
        }
        else // a < 0
        {
            // has maximum at -b/2a
            double cen = -(double)b/(double)(2*a);
            // find the most cloest two points
            auto it = upper_bound(nums.begin(), nums.end(), cen);
            int left = (it == nums.begin()) ? 0 : it-nums.begin()-1;
            int right = left+1;
            for(int i=nums.size()-1; i>=0; i--)
            {
                if( left>=0 && left<nums.size() && right>=0 && right<nums.size())
                {
                    if(fabs(nums[left]-cen)<fabs(nums[right]-cen) )
                        ans[i] = get_value(a, b, c, nums[left--]);
                    else
                        ans[i] = get_value(a, b, c, nums[right++]);
                }
                else if(left < 0) 
                    ans[i] = get_value(a, b, c, nums[right++]);
                else if(right >= nums.size())
                    ans[i] = get_value(a, b, c, nums[left--]);
            }
        }
        return ans;
    }
    
    int get_value(int a, int b, int c, int n)
    {
        return (a*n*n + b*n + c);
    }
};
