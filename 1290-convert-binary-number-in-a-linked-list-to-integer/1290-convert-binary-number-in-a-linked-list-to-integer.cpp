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
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        int num = 0;
        ListNode * temp = head;
        while(temp){
            num++;
            temp = temp->next;
        }
        temp = head;
        int ans = 0;
        while(temp){
            ans+= temp->val*pow(2,num-1);
            temp = temp->next;
            num--;
        }
        return ans;
    }
};