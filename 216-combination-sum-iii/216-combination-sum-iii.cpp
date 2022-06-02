class Solution {
public:
    void helper(int currNum,int k,int target,vector<int>& currentComb,
               vector<vector<int> >& combinations)
    {
        if(target==0){
            if(k==0)
                combinations.push_back(currentComb);
            return;
        }
        if(target<0 || k==0 || currNum>9) return;
        
        //include
        currentComb.push_back(currNum);
        helper(currNum+1,k-1,target-currNum,currentComb,combinations);
        
        //exclude
        currentComb.pop_back();
        helper(currNum+1,k,target,currentComb,combinations);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>currentComb;
        vector<vector<int> > combinations;
        helper(1,k,n,currentComb,combinations);
        return combinations;
    }
};