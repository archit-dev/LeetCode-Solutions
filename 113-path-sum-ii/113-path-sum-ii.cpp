class Solution {
    private:
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    
    void helper(TreeNode * root,int target,vector<int>&currPath,
               vector<vector<int>>& ans)
    {
        if(isLeaf(root) && target==root->val){
            currPath.push_back(root->val);
            ans.push_back(currPath);
            currPath.pop_back();
        }
        currPath.push_back(root->val);
        if(root->left) helper(root->left,target-root->val,currPath,ans);
        if(root->right) helper(root->right,target-root->val,currPath,ans);
        currPath.pop_back();
    }
    
    public:
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(!root) return ans;
        vector<int>currPath;
        helper(root,targetSum,currPath,ans);
        return ans;
    }
};