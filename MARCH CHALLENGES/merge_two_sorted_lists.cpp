class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)   return list2;
        if(list2 == NULL)   return list1;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* head;
        ListNode* temp;
        if(p1->val < p2->val){
            head = p1;
            p1 = p1->next;
        }
        else{
            head = p2;
            p2 = p2->next;
        }
    
        temp = head;
    
        while(p1 != NULL && p2 != NULL){
            if (p1->val < p2->val){
                temp ->next = p1;
                temp = temp -> next;
                p1 = p1->next;
            }
            else{
                temp->next = p2;
                temp = temp->next;
                p2 = p2->next;
            }
            // cout<<temp->val<<endl;
        }
        // temp = temp->next;
        
         while(p1 != NULL ){
            temp ->next = p1;
            temp = temp -> next;
            p1 = p1->next;
             // cout<<temp->val<<endl;
        }
        
        while(p2 != NULL){
            temp ->next = p2;
            temp = temp->next;
            p2 = p2->next;
            // cout<<temp->val<<endl;
        }
    
        return head;
    }
};