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
        stack<pair<TreeNode*,int> > st;
        st.push({root,1});
        vector<int> inorder;
        if(!root) return inorder;
        while(!st.empty()){
            TreeNode * current = st.top().first;
            int state = st.top().second;
            if(state==1){
                //preorder+= current->val;
                st.top().second++;
                if(current->left) st.push({current->left,1});
            }else if(state==2){
                //inorder
                inorder.push_back(current->val);
                st.top().second++;
                if(current->right) st.push({current->right,1});
            }else if(state==3){
                //postorder += current->val;
                st.pop();
            }
        }
        return inorder;
    }
};