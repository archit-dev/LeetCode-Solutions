class Solution {
public:
    int helper(TreeNode* root,int & ans){
        if(!root) return 0;
        int leftVal = helper(root->left,ans);
        int rightVal = helper(root->right,ans);
        int currData = root->val;
        int tilt = abs(rightVal-leftVal);
        ans+=tilt;
        return currData+rightVal+leftVal;
    }
    
    int findTilt(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};