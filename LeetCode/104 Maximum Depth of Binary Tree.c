/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int maxDepth(struct TreeNode* __root)
{
    if ( __root )
    {
        int height_of_left_tree = heightOfTree ( __root->left );
        int height_of_right_tree = heightOfTree ( __root->right );

        return 1 + (height_of_left_tree > height_of_right_tree ? height_of_left_tree : height_of_right_tree);
    }

    return 0;
}