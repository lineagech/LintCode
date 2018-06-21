class Solution {
public:
    void bitree_update(vector<int>& bin_idx_tree, int index)
    {
        while(index > 0)
        {
            bin_idx_tree[index] += 1;
            index -= index&(-index);
        }
    }
    int bitree_get(vector<int>& bin_idx_tree, int index)
    {
        int result = 0;
        while(index < bin_idx_tree.size())
        {
            result += bin_idx_tree[index];
            index += index&(-index);
        }
        return result;
    }
    
    int bin_search(vector<int>& sorted_nums, int target)
    {
        // 5, 4, 3, 2, 1
        int l = 0, r = sorted_nums.size();
        while(l < r)
        {
            int mid = (l+r)/2;
            if(sorted_nums[mid] > target)
            {
                l = mid+1;
            } 
            else
            {
                r = mid;    
            }
        }
        return l;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        vector<int> bin_idx_tree(nums.size()+1, 0);
        vector<int> sorted_nums(nums.begin(), nums.end());
        sort(sorted_nums.rbegin(), sorted_nums.rend());
        for(int i=nums.size()-1; i>=0; i--)
        {
            int index = bin_search(sorted_nums, nums[i]); 
            ans.push_back(bitree_get(bin_idx_tree, index+2));
            bitree_update(bin_idx_tree, index+1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
