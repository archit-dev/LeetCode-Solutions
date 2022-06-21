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
    void inorder(TreeNode * root, vector<int>& ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<pair<TreeNode * ,int>>st;
        TreeNode * curr = root;
        st.push({root,1});
        while(!st.empty()){
            TreeNode * node = st.top().first;
            int count = st.top().second;
            if(count==1){
                //inside preorder
                st.top().second+=1;
                if(node->left) st.push({node->left,1});
            }else if(count==2){
                //inside inorder
                ans.push_back(node->val);
                st.top().second+=1;
                if(node->right) st.push({node->right,1});
            }else{
                //inside postorder
                st.pop();
            }
        }
        return ans;
    }
};