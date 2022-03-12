/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * iterator = head;
        while(iterator){
            Node* copyNode = new Node(iterator->val);
            Node* nextNode = iterator->next;
            iterator->next = copyNode;
            copyNode->next = nextNode;
            iterator = copyNode->next;
        }
        iterator = head;
        while(iterator){
            if(iterator->random)
                iterator->next->random = iterator->random->next;
            iterator = iterator->next->next;
        }
        iterator = head;
        Node* dummy = new Node (0);
        Node* dummyPtr = dummy;
        while(iterator){
            Node* copyNode = iterator->next;
            Node* nextNode = copyNode->next;
            dummyPtr->next = copyNode;
            dummyPtr = dummyPtr->next;
            iterator->next = nextNode;
            iterator = nextNode;
        }
        return dummy->next;
    }
};