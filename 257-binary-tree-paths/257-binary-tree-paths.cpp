class Solution {
public:
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    void helper(TreeNode * root,vector<string>& ans,string currPath){
        if(isLeaf(root)){
            currPath+=to_string(root->val);
            ans.push_back(currPath);
            return ;
        }
        currPath+=to_string(root->val)+"->";
        if(root->left)helper(root->left,ans,currPath);
        if(root->right)helper(root->right,ans,currPath);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root) return ans;
        helper(root,ans,"");
        return ans;
    }
};