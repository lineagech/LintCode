class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    class MyComp
    {
    public:
        bool minComp;
        MyComp(bool minComp) { this->minComp = minComp; }
        bool operator()(int a, int b)
        {
            if(minComp) return (a>=b);
            else return (a<b);
        }
    };
     
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ans;
        if(nums.size() == 0) return ans;
        priority_queue< int,vector<int>,less<int> > maxHeap;
        priority_queue< int,vector<int>,greater<int> > minHeap;
        
        int median = nums[0];
        ans.push_back(median);
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < median)
            {
                maxHeap.push(nums[i]);
            }
            else
            {
                minHeap.push(nums[i]);
            }
            if( minHeap.size() > (maxHeap.size()+1) )
            {
                maxHeap.push(median);
                median = minHeap.top();
                minHeap.pop();
            }
            else if( maxHeap.size() > minHeap.size() )
            {
                minHeap.push(median);
                median = maxHeap.top();
                maxHeap.pop();
            }
            ans.push_back(median);
        }
        return ans;
        
    }
};
