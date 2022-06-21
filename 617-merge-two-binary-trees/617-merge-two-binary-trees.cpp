class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr) return root2;
        if(root2==nullptr) return root1;
        root1->val+=root2->val;
        TreeNode* leftTree = mergeTrees(root1->left,root2->left);
        TreeNode* rightTree = mergeTrees(root1->right,root2->right);
        root1->left = leftTree;
        root1->right = rightTree;
        return root1;
    }
};