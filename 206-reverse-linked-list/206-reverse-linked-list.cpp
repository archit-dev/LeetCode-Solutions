
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr, *curr = head, *next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};