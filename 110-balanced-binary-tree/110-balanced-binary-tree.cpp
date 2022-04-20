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
    int maxDepthOfTree(TreeNode *root){
        if(root==nullptr) return 0;
        return 1 + max(maxDepthOfTree(root->left),maxDepthOfTree(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = maxDepthOfTree(root->left);
        int right = maxDepthOfTree(root->right);
        if(abs(left-right)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};