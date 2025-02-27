/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static bool baseIsSymmetric ( struct TreeNode* __left , struct TreeNode* __right )
{
    if ( __left && __right && __left->val == __right->val )
    {
        if ( ! baseIsSymmetric ( __left->left , __right->right ) ) return false;

        return baseIsSymmetric ( __left->right , __right->left );

    }
    
    return ( __left == __right );
}

inline static bool isSymmetric(struct TreeNode* __root)
{
    return baseIsSymmetric ( __root->left , __root->right );
}