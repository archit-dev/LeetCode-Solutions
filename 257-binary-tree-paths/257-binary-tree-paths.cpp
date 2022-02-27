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
    void solve(TreeNode* root,vector<string>& ans,string pathSoFar){
        if(!root->left && !root->right){
            ans.push_back(pathSoFar+to_string(root->val));
            return;
        }
        //left subtree
        if(root->left) solve(root->left,ans,pathSoFar+to_string(root->val)+"->");
        //right subtree
        if(root->right) solve(root->right,ans,pathSoFar+to_string(root->val)+"->");
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,ans,"");
        return ans;
    }
};