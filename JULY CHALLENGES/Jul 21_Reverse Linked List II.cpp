class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right){
            
            ListNode *temp = new ListNode(0), 
            ListNode *pre = temp, *cur;
            temp -> next = head;
            
            //find the nodes to reverse the list from and to.
            for (int i = 0; i < left - 1; i++){
                pre = pre->next;
            }
            
            cur = pre -> next;
            
            //reverse the list between given nodes
            for (int i = 0; i < right - left; i++){
                ListNode *newNode = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = newNode;
            }
            
            return temp->next;
        }
};
