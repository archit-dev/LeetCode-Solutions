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
    void pathsHelper(TreeNode * root, vector<string>&paths, string currentPath){
        if(root->left==nullptr && root->right==nullptr){
            if(currentPath.size()!=0) currentPath+= "->";
            currentPath+=to_string(root->val);
            paths.push_back(currentPath);
            return ;
        }
        if(currentPath.size()==0) currentPath = to_string(root->val);
        else currentPath+= "->" + to_string(root->val);
        if(root->left) pathsHelper(root->left,paths,currentPath);
        if(root->right) pathsHelper(root->right,paths,currentPath);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        pathsHelper(root,paths,"");
        return paths;
    }
};