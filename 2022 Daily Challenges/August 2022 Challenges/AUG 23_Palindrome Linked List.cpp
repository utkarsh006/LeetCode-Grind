/* Problem :
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true


Example 2:

Input: head = [1,2]
Output: false
*/


/* Approach : (Two Pointer Approach)

With two pointers, one of which is traveling through the linked list twice as quickly as the other,
we will traverse it. The slow pointer must be in the center once the fast pointer has reached the list's end.

With slow now in the middle, we can use another variable to flip the list's rear half
so that it has a reference to the node before it and a three-way swap.
However, we should first set prev.next = null in order to stop the reverse cycle and prevent an unending loop.

After appropriately reversing the rear half so that slow is once again at the end of the list,
we can now start fast back over at the top and compare the two halves simultaneously without needing more space.

If the two pointers ever disagree on a value, we can return false; otherwise,
if both pointers successfully reach the middle, we can return true.

(Note: The comparison will end when slow hits the "dead-end" node,
therefore this procedure works regardless of whether the length of the linked list is odd or even.)
*/


class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *slow=head, *fast=head, *prev, *temp;
        while (fast && fast->next)
        {
            slow=slow->next, fast=fast->next->next;
        }
        prev=slow, slow=slow->next, prev->next=NULL;
        while (slow)
        {
            temp=slow->next, slow->next=prev, prev=slow, slow=temp;
        }
        fast=head, slow=prev;
        while (slow)
        {
            if (fast->val!=slow->val)
            {
                return false;
            }
            else
            {
                fast=fast->next, slow=slow->next;
            }
        }
        return true;
    }
};


/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
