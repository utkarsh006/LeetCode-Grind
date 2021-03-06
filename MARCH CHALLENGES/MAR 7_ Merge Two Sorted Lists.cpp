class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        if(list1 == NULL)   return list2; // returning list2 when first is empty
        if(list2 == NULL)   return list1;  // returning list 1 when list 2 is empty
        
        ListNode* p1 = list1;  // pointer to list 1
        ListNode* p2 = list2; // pointer to list 2
        ListNode* head; // head of final list
        ListNode* temp; // pointer to find enxt value to add ot list
        
        // checking for the smaller head of two whoch becomes head of final list
        if(p1->val < p2->val){
            head = p1;
            p1 = p1->next;
        }
        else{
            head = p2;
            p2 = p2->next;
        }
    
        temp = head;
        // checking for smaller value and adding it to the head
        // then incrementing the pointer of that list until either becomes null
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

        }

        
        
        // checking for any remaining elements in list 1
         while(p1 != NULL ){
            temp ->next = p1;
            temp = temp -> next;
            p1 = p1->next;
             // cout<<temp->val<<endl;
        }
        
        // checking for any remaining elements in list 2
        while(p2 != NULL){
            temp ->next = p2;
            temp = temp->next;
            p2 = p2->next;
        }
    
        return head;
    }
};
