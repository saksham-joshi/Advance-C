/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void baseCountNodes(struct TreeNode *__left, struct TreeNode *__right, unsigned int *__count)
{
    if (__left)
    {
        ++(*__count);
        
        baseCountNodes(__left->left, __left->right, __count);
    }

    if (__right)
    {
        ++(*__count);

        baseCountNodes(__right->left, __right->right, __count);
    }
}
int countNodes(struct TreeNode *__root)
{
    unsigned output = 0;

    if (__root)
    {
        ++output;

        baseCountNodes(__root->left, __root->right, &output);
    }

    return output;
}