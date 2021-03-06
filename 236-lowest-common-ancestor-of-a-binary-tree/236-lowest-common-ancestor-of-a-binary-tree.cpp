/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p==root || q==root) return root;
        TreeNode * leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode * rightAns = lowestCommonAncestor(root->right,p,q);
        if(leftAns && !rightAns) return leftAns;
        if(!leftAns && rightAns) return rightAns;
        if(!leftAns && !rightAns) return nullptr;
        return root;
    }
};