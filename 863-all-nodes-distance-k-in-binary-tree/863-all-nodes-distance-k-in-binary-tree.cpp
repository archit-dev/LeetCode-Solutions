class Solution {
private:
    void findParent(TreeNode* root,unordered_map<TreeNode * ,TreeNode * >& parents)
    {
        if(!root) return;
        if(root->left){
            parents[root->left] = root;
            findParent(root->left,parents);
        }
        if(root->right){
            parents[root->right] = root;
            findParent(root->right,parents);   
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root) return ans;
        unordered_map<TreeNode * , TreeNode*> parents;
        findParent(root,parents);
        queue<TreeNode *> q;
        q.push(target);
        int dist = 0;
        unordered_map<TreeNode * , bool> vis;
        vis[target] = true;
        while(!q.empty()){
            if(dist==k) break;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode * curr = q.front();
                q.pop();
                if(parents.find(curr)!=parents.end()){
                    TreeNode * par = parents[curr];
                    if(!vis[par]){
                        q.push(par);
                        vis[par] = true;
                    }
                }
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
            }
            dist+=1;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};