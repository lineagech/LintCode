class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int n=nums.size();
        int l=0, h=n-1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] )
            {
                return mid;
            }
            if(mid==0){
                if(nums[mid]>nums[mid+1]) return mid;
                else l=mid+1;
            }
            else{
                if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1] )
                {
                    h=mid-1;
                }
                else if(nums[mid]>nums[mid-1]
                        && nums[mid]<nums[mid+1] )
                {
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            
        }
        return l;
    }

};
