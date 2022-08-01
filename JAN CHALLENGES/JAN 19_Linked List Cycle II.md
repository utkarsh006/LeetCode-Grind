## Linked List Cycle II

## Problem Statement

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

## Example

Input: head = [3,2,0,-4], pos = 1

Output: tail connects to node index 1

Explanation: There is a cycle in the linked list, where tail connects to the second node.


## Approach - 1 (Using Hashmap)

 1. Idea is that while traversing all the nodes we will store the nodes in our hashmap along with marking them as visited in hashmap.

 2. So if the Linkedlist will contain cycle then we will definately reach to that node again where cycle starts.

 3. When we will reach that node, if that node is marked as visited in our hashmap then we can simply return that node and that will be the answer.


 ## Code
 
 ```cpp
 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp)
        {
            //if already visited then return the node
            if(mp[temp] == 1)
            {
                return temp;
            }
            //making the node (temp) mark as visited in the hashmap
            mp[temp]=1;
            temp=temp->next;
        }
        //if any answer is not returned from above loop then it doesn't contain cycle so return NULL
        return 0;
    }
};

 ```


- #### Time Complexity: O(N)    -- For traversing the linkedlist

- #### Space Complexity: O(N)   -- We are storing the nodes in map




## Approach -2 (Slow & Fast pointer) , Space Optimized Approach

1. Will use two pointers slow and fast where slow will move by one step and fast will move by 2 steps.

2. So till slow doesn't become equal to fast , or fast and fast->next exist and doesn't become null, we will keep on moving our both pointers.

3. If linkedlist doesn't contains cycle then eventually either fast or fast->next will be NULL & will move out of the while loop.

4. Else, if there is cycle then slow will become equal to fast & as this condition occurs we will break the while loop & will move any of the pointer (slow or fast) to head.

5. Suppose fast=head then slow will be at the node where it was & fast at head , from here both will take one step at a time.

6. We are doing this because it's not necessary the node at which both slow & fast meets is the starting of the cycle , it can be any node. (For ex: head = [3,2,0,-4], pos = 1 )Try this example out, they both meet at -4 & starting of cycle is 2.

7. So when fast starts from head & slow starts from the node where it was then both the pointers will keep on moving 1 step at a time till slow!= fast , as they become equal we will return that node, either return slow or return fast (same thing!)

8. Base Case : If head is NULL or head->next is NULL(means only 1 node present) then we will return NULL as there is no cycle.


 ## Code
 
 ```cpp

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //if linkedlist contains is NULL or contains only one node
        // then there will be no cycle so will return NULL
        if(head==NULL || head->next == NULL) return NULL;

        //will run the loop until fast or fast->next becomes NULL 
        // if there is cycle then fast will not become NULL otherwise it will become NULL
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            // if we got a node where fast and slow are equal we will break the loop
            // we got the cycle here
            if(slow==fast)
            {
                break;
            }
        }

        // if fast have became NULL & there is no cycle then we will not go inside this condition
        if(slow==fast)
        {
            // will move fast to head
            fast=head;

            // until fast & slow doesn't become equal again we will keep the moving one step at a time
            while(slow!=fast) 
            {
                 slow=slow->next;
                 fast=fast->next;
            }
            return slow;
        }
        return 0;
    }
};

```

- #### Time Complexity: O(N)    -- For traversing the linkedlist

- #### Space Complexity: O(1)   --Constant Space

