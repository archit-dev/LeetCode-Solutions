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
    void giveSortedArray(TreeNode * root, vector<int>&inorder){
        if(!root) return;
        giveSortedArray(root->left,inorder);
        inorder.push_back(root->val);
        giveSortedArray(root->right,inorder);
    }
    int minDiffInBST(TreeNode* root) {
        //inorder traversal gives sorted order
        //so basically we need to return min diff
        //of neighbours
        vector<int> inorder;
        giveSortedArray(root,inorder);
        int ans = INT_MAX;
        for(int i=1;i<inorder.size();i++){
            ans = min(ans,abs(inorder[i]-inorder[i-1]));
        }
        return ans;
    }
};