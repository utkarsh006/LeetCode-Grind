/*
Problem: Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program.
If you correctly return the intersected node, then your solution will be accepted.

*/

/*
Example:
        Example 1 :

        Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
        Output: Intersected at '8'
        Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
        From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
        There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
        - Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. 
        In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.

        Example 2 :
        Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
        Output: No intersection
        Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect,
        intersectVal must be 0, while skipA and skipB can be arbitrary values.
        Explanation: The two lists do not intersect, so return null.
*/

/*
Approach 1: (Length difference)

1. In this approach, we will find the length of both the linkedlist and will take their difference , 
   after that we'll make the two pointers reach at same position & then we'll find the intersection point.

2. Keep 2 pointers temp1 on the headA(first LL head), temp2 on headB(second LL head)

3. Now find the length of both the LL by traversing temp1 and temp2 from heads to NULL and simultaneously increment their respective counts.

4. Again keep temp1 at headA & temp2 at headB.

5. Now while the temp1 and temp2 nodes are not equal , keep running this loop & check which LL length is greater.

6. If length of temp1 is greater then move temp1 one step forward and decrement the length by 1.
   If length of temp2 is greater then move temp2 one step forward and decrement the length by 1. 
   If the length is equal then move both temp1 and temp2 one step forward.

7. Keep performing step 6 until temp1!=temp2 , if they become equal we'll come out of loop & will return temp1.
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int length1 = 0, length2 = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1)
        {
            length1++;
            temp1 = temp1->next;
        }
        while (temp2)
        {
            length2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        while (temp1 != temp2)
        {
            if (length1 > length2)
            {
                temp1 = temp1->next;
                length1--;
            }
            else if (length2 > length1)
            {
                temp2 = temp2->next;
                length2--;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return temp1;
    }
};

/*
Time Complexity: O(N+M)
Space Complexity:O(1)
*/

/*
Approach 2: (Two pointers)

1. Keep 2 pointers a on the headA(first LL head), b on headB(second LL head).

2. Now run a while loop till node a!=b , check for the condition if a!=Null then move a one step forward & if b!=Null then move b one step forward.

3. When a reaches to null then assign headB to a (a=headB), & when b reaches to null then assign headA to a (b=headA).

4. Atlast when they'll intersect then return a or b.
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b)
    {
        if (a == NULL)
            a = headB;
        else
            a = a->next;

        if (b == NULL)
            b = headA;
        else
            b = b->next;
    }
    return b;
}

/*
Time Complexity: O(N+M)
Space Complexity:O(1)
*/