class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
         ListNode* headK = head;
         int cnt = k-1;     // be careful of 1-based index
        while (cnt > 0 )
        {
            headK = headK->next;
            cnt--;
        }
        ListNode* tailK = head, *p = headK;
        
        while (p->next != NULL) 
        {
            p = p->next;
            tailK = tailK->next;
        }
       swap(headK->val,tailK->val);
        return head;
    }
    
};
   
