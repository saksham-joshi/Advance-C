/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef unsigned short int u16_t;

inline static u16_t absMinus(u16_t __lhs, u16_t __rhs)
{
    return (__lhs > __rhs) ? (__lhs - __rhs) : (__rhs - __lhs);
}

static u16_t baseIsBalanced(struct TreeNode *__node, bool *__output)
{
    if (__node)
    {
        u16_t left_height = baseIsBalanced(__node->left, __output);

        if (!*__output) return 0;

        u16_t right_height = baseIsBalanced(__node->right, __output);

        if (!*__output) return 0;

        if (absMinus(left_height, right_height) > 1) *__output = false;

        return 1 + (left_height > right_height ? left_height : right_height);
    }

    return 0;
}

inline static bool isBalanced(struct TreeNode *__root)
{
    if (!__root) return true;

    bool output = true;

    baseIsBalanced(__root, &output);

    return output;
}