inline static void deleteNode(struct ListNode* node) {
    
    struct ListNode* next = node->next;

    node->val = next->val;

    node->next = next->next;

    free(next);
}

/* Another faster code but creates memory leak which 
 * is not detected by Leetcode
*/

inline static void deleteNode(struct ListNode* node) {

    node->val = node->next->val;

    node->next = node->next->next;

}