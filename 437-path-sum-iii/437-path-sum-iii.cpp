class Solution {
public:
    int helper(TreeNode * root,unordered_map<long long,int>& sumMap,int target,long long runSum){
        if(!root) return 0;
        runSum+=root->val;
        int rem = runSum-target;
        int count = 0;
        if(sumMap.find(rem)!=sumMap.end()){
            //first time encounter
            count+=sumMap[rem];
        }
        
        sumMap[runSum]+= 1;
        
        count+=helper(root->left,sumMap,target,runSum);
        count+=helper(root->right,sumMap,target,runSum);
        
        sumMap[runSum]-=1;
        return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        //similar to subarray sum equals k
        unordered_map<long long,int>sumMap;
        if(!root) return 0;
        sumMap[0] = 1;
        return helper(root,sumMap,targetSum,0);
    }
};