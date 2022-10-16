Problem Link :  https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Approach:
Lets  c be the total nodes in the linked list. The Nth node from the end is (c-N+1)th node from the beginning.
So the problem simplifies down to that we have to find  (c-N+1)th node from the beginning and delete it.
  
Time Complexity: O(c) where c is the size of the linked list
SpaceComplexity: O(1)
  
Solution:
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
            ListNode* node=head;
            int c=0;
            // c is the counter,to count the number of nodes in the linked list
            while(node!=NULL)
            {
                    node=node->next;
                    c++;
            }
            //if the node to be deleted is head, then simply point the head to the next node 
            if((c-n)==0)
            {
                    node=head;
                    head=head->next;
                    delete(node);
                 
            }
            //if the node to be deleted is not head,then
            //1.keep iterating from head till (n-c)th node and delete it 
            else
            {
                    cout<<head->val;
                    node=head;
                    cout<<node->val;
                    for(int i=1;i<(c-n);i++)
                    {
                            node=node->next;
                    }
                    ListNode* temp=node;
                    temp=node->next;
                    node->next=temp->next;
                    delete(temp);
            }
            return head;
            
            
    }
};

