/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> &A) {
        if(A.size() == 0) return NULL;
        stack<TreeNode*> stack;
        for( int i = 0; i < A.size(); i++ )
        {
            TreeNode* curr = new TreeNode(A[i]);
            while( !stack.empty() && stack.top()->val<A[i] ){
                curr->left = stack.top();
                stack.pop();
            }
            if(!stack.empty()) stack.top()->right = curr;
            stack.push(curr);
        }
        while(stack.size() > 1) stack.pop();
        return stack.top();
    }
    
};
