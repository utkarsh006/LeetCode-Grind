class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(head== NULL)
            return 0;
        ListNode *fast = head->next;
        ListNode *slow = head;
        
        while(fast !=NULL && fast -> next !=NULL)
        {  
            if(fast==slow)
                   return 1;
             fast = fast->next->next;
             slow = slow->next;
            
        }
        return 0;
    }
};
