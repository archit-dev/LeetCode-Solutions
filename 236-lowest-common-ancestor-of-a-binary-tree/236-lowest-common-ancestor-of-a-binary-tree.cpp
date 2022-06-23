class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode * left_ = lowestCommonAncestor(root->left,p,q);
        TreeNode * right_ = lowestCommonAncestor(root->right,p,q);
        if(!left_ && right_) return right_;
        if(left_ && !right_) return left_;
        if(!left_ && !right_) return nullptr;
        return root;
    }
};