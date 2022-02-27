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
    void inorder(TreeNode* root,int &minVal, TreeNode* &prev){
        if(!root) return;
        inorder(root->left,minVal,prev);
        if(prev) minVal = min(minVal,root->val - prev->val);
        prev = root;
        inorder(root->right,minVal,prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minVal = INT_MAX;
        TreeNode* previous = nullptr;
        inorder(root,minVal,previous);
        return minVal;
    }
};