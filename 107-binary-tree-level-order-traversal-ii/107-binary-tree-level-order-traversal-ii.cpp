
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        
        queue<TreeNode* >q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                TreeNode * node = q.front();
                q.pop();
                temp[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};