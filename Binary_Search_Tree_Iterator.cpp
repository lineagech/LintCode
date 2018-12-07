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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    BSTIterator(TreeNode * root) {
        while( root != NULL )
        {
            path.push(root);
            root = root->left;
        }        
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return (path.size() != 0);
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        TreeNode* node = path.top();
        path.pop();
        if( node->right != NULL )
        {
            path.push(node->right);
            TreeNode* tmp = node->right;
            while( tmp->left != NULL ) {
                path.push(tmp->left);
                tmp = tmp->left;
            }
        }
        return node;
    }
    stack<TreeNode*> path;
};
