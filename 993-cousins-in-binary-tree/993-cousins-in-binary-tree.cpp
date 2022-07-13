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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,nullptr});
        int xLevel=-1, xParent = -1, yLevel = -1, yParent = -1;
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode * curr = q.front().first;
                TreeNode * parent = q.front().second;
                q.pop();
                if(curr->val==x){
                    xLevel = level;
                    if(parent!=nullptr)xParent = parent->val;
                }
                if(curr->val==y){
                    yLevel = level;
                    if(parent!=nullptr)yParent = parent->val;
                }
                if(curr->left) q.push({curr->left,curr});
                if(curr->right) q.push({curr->right,curr});
                
            }
            level+=1;
        }
        return xLevel==yLevel && xParent!=yParent;
    }
};