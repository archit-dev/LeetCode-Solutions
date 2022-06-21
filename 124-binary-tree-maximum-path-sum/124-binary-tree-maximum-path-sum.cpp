class Solution {
public:
    int maxPathHelper(TreeNode * root,int & pathSum){
        if(!root) return 0;
        int leftPathSum = max(0,maxPathHelper(root->left,pathSum));
        int rightPathSum = max(0,maxPathHelper(root->right,pathSum));
        pathSum = max(pathSum,root->val+leftPathSum+rightPathSum);
        return root->val + max(leftPathSum,rightPathSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        maxPathHelper(root,pathSum);
        return pathSum;
    }
};