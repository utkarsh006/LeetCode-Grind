/*
Problem : Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Example:
        Example 1:
        Input: head = [4,2,1,3]
        Output: [1,2,3,4]

        Example 2:
        Input: head = [-1,5,3,4,0]
        Output: [-1,0,3,4,5]

        Example 3:
        Input: head = []
        Output: []
*/


/*
Algorithm:

1. Find the middle element of linkedlist.

2. Divide the linkedlist into two halves.

3. Perform merge 2 sorted linkedlist to megre the linkedlist in sorted order. 
*/

/*
Approach:
1. Base Case: If head  is Null or head->next is null then we'll return head because we dont have anything to do.

2. Firstly to find the middle element of linkedlist we will use fast and slow pointer approach (hare-tortoise).

3. We'll keep a temp pointer also which will be just behind slow, we're keeping temp because when we will get the middle of linkedlist as slow 
then from slow new linkedlist will start so we will do temp=NULL.

4. Thereby we'll have 2 linkedlist one from head and other from slow.

5. once this done, we will again pass both the linkedlist one by one in sortList so the linkedlist can be further 
subdivided and all the process will happen recursively. We'll keep on dividing until we get linkedlist of 1 node each in head and slow.

6. After that we'll pass these linkedlist in mergeList function and there we'll perform the code of merge 2 sorted linkedlist and 
we'll get linkedlist as merged in a sorted order.

7. Atlast after these all operation are done recursively for every linkedlist we'll return the merge linkedlist.
*/

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *temp;

        if (!head || !head->next) //Base Case
            return head;

        // Two pointer approach for finding middle of linkedlist
        while (fast && fast->next)
        {
            // temp will be just behind slow
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //  Make temp->next =NULL so that we'll get one linkedlist from head to temp and other from slow
        temp->next = 0;

        // will recursively call pass the two divided linkedlist until we get linkedlist of 1 node each
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        // call for merge 2 sorted linkedlist
        return mergelist(l1, l2);
    }

    ListNode *mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        if (!l1)
            return l2;
        if (!l2)
            return l1;
            // When both the linkedlist exist compare the data of the nodes and merge accordingly.
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            }
            else
            {
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
        }
        // If l2 is NULL but l1 is not then we will add the rest nodes of l1 in dummy.
        if (l1)
        {
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;
        }
        // If l1 is NULL but l2 is not then we will add the rest nodes of l2 in dummy.
        if (l2)
        {
            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;
        }
        return temp->next;
    }
};

/*
Time Complexity:O(n logn)
Space Complexity:O( logn)
*/