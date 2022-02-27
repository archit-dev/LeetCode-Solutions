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
    int solve(TreeNode* root,int move){
        if(!root) return 0;
        if(!root->left && !root->right){
            //leaf node 
            if(move==0) return root->val; //left subtree
            else return 0; //right subtree
        }
        return solve(root->left,0) + solve(root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,-1);
    }
};