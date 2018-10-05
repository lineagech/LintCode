class Solution {
public:
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> twoSum(TreeNode * root, int n) {
        // write your code here
        vector<int> nums;
        int left, right;
        inorder(root, nums); // sorted array
        
        left = 0; right = nums.size()-1;
        int nums_len = nums.size();
        while(left < right)
        {
            if( nums[left] + nums[right] == n )
                return {nums[left], nums[right]};
            if( left < nums_len && nums[left] + nums[right] < n ){
                while( nums[left] == nums[left+1] ) left++;
                left++;
            }
            else if( right >= 0 && nums[left] + nums[right] > n ){
                while( nums[right] == nums[right-1] ) right--;
                right--;
            }
        }
        return vector<int>();
    }
    void inorder(TreeNode * root, vector<int>& nums)
    {   
        if(root == NULL) return;
        if( root->left != NULL )
            inorder(root->left, nums);
        nums.push_back(root->val);
        if( root->right != NULL )
            inorder(root->right, nums);
    }
};
