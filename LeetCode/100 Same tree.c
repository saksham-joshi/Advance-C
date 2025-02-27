/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static bool isSameTree(struct TreeNode* __tree1, struct TreeNode* __tree2)
{
    if ( __tree1 && __tree2)
    {
        if( __tree1->val != __tree2->val) return false;
            
        if ( ! isSameTree ( __tree1->left , __tree2->left) ) return false;

        return isSameTree( __tree1->right , __tree2->right);
    }
    
    return ( __tree1 == __tree2 );
}