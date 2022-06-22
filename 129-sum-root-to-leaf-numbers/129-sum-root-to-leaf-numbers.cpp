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
    bool isLeaf(TreeNode * root){
        return !root->left && !root->right;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode *,int> >q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode * node = q.front().first;
                int curNum = q.front().second*10 + node->val;
                q.pop();
                if(node->left) q.push({ node->left,curNum});
                if(node->right) q.push({node->right,curNum});
                if(isLeaf(node)) ans+=curNum;
            }
        }
        return ans;
    }
};