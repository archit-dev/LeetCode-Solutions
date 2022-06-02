class Solution {
public:
    void helper(int currNum,int k,int target,vector<int>& currentComb,
               vector<vector<int> >& combinations,vector<bool>& vis)
    {
        if(target==0){
            if(k==0)
                combinations.push_back(currentComb);
            return;
        }
        if(target<0 || k==0 || vis[currNum] || currNum>9) return;
        
        //include
        vis[currNum] = 1;
        currentComb.push_back(currNum);
        helper(currNum+1,k-1,target-currNum,currentComb,combinations,vis);
        
        //exclude
        vis[currNum] = 0;
        currentComb.pop_back();
        helper(currNum+1,k,target,currentComb,combinations,vis);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>currentComb;
        vector<vector<int> > combinations;
        vector<bool>vis(10,false);
        helper(1,k,n,currentComb,combinations,vis);
        return combinations;
    }
};