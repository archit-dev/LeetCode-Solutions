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
    int depth(TreeNode * root){
        if(root==nullptr) return 0;
        int lh = depth(root->left);
        int rh = depth(root->right);
        if(lh==-1 || rh ==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(depth(root->left),depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        return depth(root)!=-1;
    }
};