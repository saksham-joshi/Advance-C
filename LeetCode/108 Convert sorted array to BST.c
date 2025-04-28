/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
inline static struct TreeNode *generateTreeNode(int __value)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    node->val = __value;

    node->left = node->right = 0;

    return node;
}

static void baseSortedArrayToBST(const int *__nums, unsigned short int __left_index, unsigned short int __right_index, struct TreeNode *__node)
{
    if (__left_index >= __right_index) return;

    unsigned int mid_index = __left_index + (__right_index - __left_index) / 2;

    struct TreeNode *new_node = generateTreeNode(__nums[mid_index]);

    (new_node->val < __node->val) ? (__node->left = new_node) : (__node->right = new_node);

    if (__left_index == __right_index) return;

    baseSortedArrayToBST(__nums, __left_index, mid_index, new_node);
    baseSortedArrayToBST(__nums, mid_index + 1, __right_index, new_node);
}

inline static struct TreeNode *sortedArrayToBST(int *__nums, int __len)
{
    struct TreeNode *output = generateTreeNode(__nums[__len / 2]);

    baseSortedArrayToBST(__nums, 0, __len / 2, output);

    baseSortedArrayToBST(__nums, (__len / 2) + 1, __len, output);

    return output;
}