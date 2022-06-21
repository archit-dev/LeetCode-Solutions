class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long width = 1;
        queue<pair<TreeNode * , long long> >q;
        q.push({root,0});
        while(!q.empty()){
            long long n = q.size();
            long long minIdx = q.front().second;
            long long low = 0, high = 0;
            for(long long i=0;i<n;i++){
                TreeNode * node = q.front().first;
                long long currIdx = q.front().second-minIdx;
                q.pop();
                if(i==0) low = currIdx;
                if(i==n-1) high = currIdx;
                
                if(node->left){
                    q.push({node->left,2*currIdx+1});
                }
                if(node->right){
                    q.push({node->right,2*currIdx+2});
                }
            }
            width = max(high-low+1,width);
        }
        return width;
    }
};