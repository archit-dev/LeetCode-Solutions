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
    bool isPalindrome(int arr[]){
        int odd = 0 ;
        for(int i=0;i<10;i++){
            if(arr[i]%2!=0) odd+=1;
            if(odd>1) return false;
        }
        return true;
    }
    
    bool isLeaf(TreeNode * root) {
        return !root->left && !root->right;
    }
    
    int helper(TreeNode * root,int arr[])
    {
        if(!root) return 0;
        int count = 0;
        
        arr[root->val]+=1;
        
        if(isLeaf(root)){
            if(isPalindrome(arr)) count+=1;
        }
        if(root->left) count+=helper(root->left,arr);
        if(root->right) count+=helper(root->right,arr);
        
        arr[root->val]-=1;
        return count;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int arr[10] = {0};
        return helper(root,arr);
    }
};