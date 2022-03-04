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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode();
        ListNode * head = dummy;
        int carry = 0;
        while(l1 && l2){
            int sum = carry+l1->val+l2->val;
            dummy->next = new ListNode(sum%10);
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
            carry=sum/10;
        }
        while(l1){
            int sum = carry+l1->val;
            carry=sum/10;
            dummy->next = new ListNode(sum%10);
            dummy=dummy->next;
            l1=l1->next; 
        }
        while(l2){
            int sum = carry +l2->val;
            carry=sum/10;
            dummy->next = new ListNode(sum%10);
            dummy=dummy->next;
            l2=l2->next; 
        }
        if(carry) dummy->next=new ListNode(1);
        return head->next;
    }
};