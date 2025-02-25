/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static struct ListNode *baseIsPalindrome(struct ListNode *__iterator, struct ListNode *__head, bool *__output)
{
    if (__iterator->next)
    {
        struct ListNode *next_node = baseIsPalindrome(__iterator->next, __head, __output);

        if (*__output) __head = next_node;

        else return NULL;
    }

    if (__iterator->val != __head->val) *__output = false;

    return __head->next;
}

inline static bool isPalindrome(struct ListNode *__head)
{
    bool output = true;

    baseIsPalindrome(__head, __head, &output);

    return output;
}