/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        vector<vector<Node*> > nodes;
        vector<Node*> temp1;
        temp1.push_back(root);
        nodes.push_back(temp1);
        while(!q.empty()){
            int n = q.size();
            vector<Node*> temp;
            for(int i=0;i<n;i++){
                Node * curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    temp.push_back(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                    temp.push_back(curr->right);
                }
            }
            nodes.push_back(temp);
        }
        for(int i=0;i<nodes.size();i++){
            //level i
            for(int j=0;j<nodes[i].size();j++){
                if(j==nodes[i].size()-1){
                    nodes[i][j]->next = nullptr;
                }else{
                    nodes[i][j]->next = nodes[i][j+1];
                }
            }
            
        }
        return root;
    }
};