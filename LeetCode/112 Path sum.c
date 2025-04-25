/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

inline static bool isChildNode( struct TreeNode* __node )
{
    return (__node->left == 0 && __node->right == 0);
}


static void baseHasPathSum( struct TreeNode* __node, bool* __output, int __current_sum, const int __target )
 {
 
    if ( __node ) __current_sum += __node->val;
 
    if ( __node && isChildNode( __node ) && __current_sum == __target )
    {
        *__output = true;
    }
    else if ( __node )
    {
        baseHasPathSum( __node->left , __output, __current_sum , __target );
 
        if ( *__output ) return;
 
        baseHasPathSum( __node->right , __output, __current_sum, __target );
    }
}

inline static bool hasPathSum(struct TreeNode* __root, int __target_sum)
{
    bool output = false;
 
    baseHasPathSum( __root, &output, 0, __target_sum );
 
    return output;
}