/*
Intuition : Since we are given the access to ONLY the node to be deleted, so we will swap the value of the node to be deleted with its next node and
then using the address of given node to delete the another .

1. Time Complexity = O(1)
2. Space Complexity = O(1)
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        ListNode* curr = node;
        
        swap(curr->val,curr->next->val);
        
        curr->next = curr->next->next;
        
    }
};
