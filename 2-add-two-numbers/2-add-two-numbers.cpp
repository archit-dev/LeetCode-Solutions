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
        if(!l1 || !l2) return l1==nullptr ? l2 : l1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* sumList = new ListNode();
        ListNode* sumListPtr = sumList;
        while(temp1 && temp2){
            int currSum = (temp1->val+temp2->val+carry)%10;
            
            sumListPtr->next = new ListNode(currSum);
            sumListPtr = sumListPtr->next;

            carry = (temp1->val+temp2->val+carry)/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        while(temp1){
            int currSum = (temp1->val+carry)%10;
            
            sumListPtr->next = new ListNode(currSum);
            sumListPtr = sumListPtr->next;
            
            carry = (temp1->val+carry)/10;
            temp1 = temp1->next;
            
        }
        while(temp2){
            int currSum = (temp2->val+carry)%10;
            
            sumListPtr->next = new ListNode(currSum);
            sumListPtr = sumListPtr->next;
            
            carry = (temp2->val+carry)/10;
            temp2 = temp2->next;
        }
        if(carry){
            sumListPtr->next = new ListNode(carry);
        }
        return sumList->next;
        
    }
};