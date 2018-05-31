class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The maximum number inside the window at each moving
     */
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        // write your code here
        vector<int> ans;
        deque< pair<int,int> > queue;
        if(nums.size() == 0) return ans;
        
        for(int i=0; i<min((int)nums.size(),k); i++)
        {   
            while(queue.size()>0 && queue.back().first < nums[i]) 
                queue.pop_back();
            queue.push_back(make_pair(nums[i],i)); 
        }    
        if(nums.size() <= k){
            ans.push_back(queue.front().first);
            return ans;
        }
        for(int i=k; i<nums.size(); i++)
        {
            int pop_idx = i-k;
            ans.push_back(queue.front().first);
            while( queue.size()>0 && queue.front().second <= pop_idx ) 
                queue.pop_front();
            while( queue.size()>0 && queue.back().first < nums[i])
            {
                queue.pop_back();
            }
            queue.push_back(make_pair(nums[i],i));
        }
        ans.push_back(queue.front().first);
        return ans;
    }
};
