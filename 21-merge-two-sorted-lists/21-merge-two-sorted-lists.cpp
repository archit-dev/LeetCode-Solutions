class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ptr1 = list1 , *ptr2 = list2;
        
        ListNode * tempHead = new ListNode(-1);
        ListNode * dummy = tempHead;
        
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                dummy->next = ptr1;
                ptr1=ptr1->next;
            }
            else{
                dummy->next = ptr2;
                ptr2=ptr2->next;
            }
            dummy = dummy->next;
        }
        
        if(ptr1) dummy->next = ptr1;
        if(ptr2) dummy->next = ptr2;
        
        return tempHead->next;
    }
};