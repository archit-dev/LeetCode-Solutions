class Solution {
    private:
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(isLeaf(root)){
            if(targetSum==root->val) return true;
            else return false;
        }
        return hasPathSum(root->left,targetSum-root->val) ||
                hasPathSum(root->right,targetSum-root->val);
    }
};