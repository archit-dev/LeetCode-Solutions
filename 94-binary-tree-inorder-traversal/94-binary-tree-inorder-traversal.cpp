/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        stack<pair<TreeNode*,int> > st;
        st.push({root,1});
        while(!st.empty()){
            int state = st.top().second;
            TreeNode * curr = st.top().first;
            if(state==1){
                st.top().second++;
                if(curr->left!=nullptr) st.push({curr->left,1}) ;
            }
            else if(state==2){
                st.top().second++;
                inorder.push_back(curr->val);
                if(curr->right!=nullptr) st.push({curr->right,1});
            }
            else{
                st.pop();
            }
        }
        return inorder;
    }
};