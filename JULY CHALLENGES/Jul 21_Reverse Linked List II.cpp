class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right){
            ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
            dummy->next = head;
            for (int i = 0; i < left - 1; i++){
                pre = pre->next;
            }
            cur = pre->next;
            for (int i = 0; i < right - left; i++){
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            return dummy->next;
        }
};
