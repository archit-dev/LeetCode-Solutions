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
    #define ll unsigned long long
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll> > q;
        q.push({root,0});
        ll ans = 0;
        while(!q.empty()){
            ll n = q.size();
            ll first,last;
            ll min_ = q.front().second;
            for(int i=0;i<n;i++){
                TreeNode* currNode = q.front().first;
                ll currIndex = q.front().second;
                q.pop();
                if(i==0) first = currIndex;
                if(i==n-1) last = currIndex;
                if(currNode->left) q.push({currNode->left,2*currIndex+1}); 
                if(currNode->right) q.push({currNode->right,2*currIndex+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};