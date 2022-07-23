/*
Intuition :- 
1. Create two dummy ListNode say lesser_x and greater_x.
2. Iterate over the given LinkedList to populate lesser_x with values less than x and greater_x with values greater than or equal to x.
3. Finally, join the next of lesser_x to the next of greater_x.
4. Return next of the lesser_x.

Reason why we are joining lesser_x->next  to greater_x->next :- its because the 1st node of greater_x is the dummy node with value 0, that we created earlier and we don't need it.

Reason why we are returning lesser_x->next :- its because the 1st node of lesser_x is the dummy node that we created earlier and we don't need it.

Time Complexity = O(N) , Since we are iterating over the entire linked list to populate lesser_x & greater_x

Space Complexity =O(1);we have not used any extra space,we are only reforming the original list. 

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        //creating dummy nodes
        ListNode* lesser_x = new ListNode(0) ;//will have nodes having values less than x
        ListNode* greater_x = new ListNode(0);//will have nodes having values greater than or equal to x
        
        ListNode* lesser = lesser_x;
        ListNode* greater = greater_x;
        
        
        ListNode* curr = head;
        while(curr != NULL)
        {
            //if value of a node is less than x
            //then we'll add it to lesser 
            //otherwise we'll add it to greater
            if(curr->val < x)
            {
                lesser->next = curr;
                lesser = lesser->next;
            }
            else
            {
                greater->next = curr;
                greater = greater->next;
            }
            
            curr = curr->next;
        }
        greater->next = NULL;
        lesser->next = greater_x->next;
        
        return lesser_x->next;
    }
};
