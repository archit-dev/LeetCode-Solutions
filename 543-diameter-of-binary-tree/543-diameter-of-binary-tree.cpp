class Solution {
public:
    int depth(TreeNode * root,int & dia){
        if(root==nullptr) return 0;
        int lh = depth(root->left,dia);
        int rh = depth(root->right,dia);
        dia = max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root,diameter);
        return diameter;
    }
};