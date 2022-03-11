class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
       if(head==NULL || head->next==NULL || k==0)
           return head;
        
      //compute the length
        ListNode* curr = head;
        int len=1;
        while(curr->next && ++len)  
            curr = curr->next;
        
          curr->next=head; // last node points to head
          k = k%len;
          k = len-k;
          while(k--)
              curr = curr->next; // curr ko k tak pahuchade
        
        // make the head node and break the connection
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};
