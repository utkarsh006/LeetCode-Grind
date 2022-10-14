Delete the middle of linked list

Problem:
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Input: head = [1,2,3,4]
Output: [1,2,4]

Approach:
Declare two nodes slow and fast and point them to head. Keep moving the slow pointer by one(i.e slow=slow->next) and fast by two(i.e fast=fast->next->next)
this way the when the fast pointer will reach the end then slow pointer will point to the middle of the linked list.We can store the previous node of slow
in the prev pointer and simply do (prev->next=slow->next).

Solution (using tortoise method)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    if(head==NULL || head->next==NULL) return NULL;       
    ListNode *prev=NULL, * slow=head, * fast=head;       
    while(fast!=NULL and fast->next!=NULL){                  
        prev=slow;                                       
        slow=slow->next;           
        fast=fast->next->next;                  
    }
    
    
    prev->next=slow->next;                               
    delete slow;                                        
    return head;                                         
    }
};
Time Complexity: O(n/2)
Space Complexity: O(1)
