class Solution {
public:
    void helper(int idx,int target,vector<int>& candidates,vector<int>& currentComb,
               vector<vector<int> >& combinations)
    {
        if(target==0){
            combinations.push_back(currentComb);
            return;
        }
        if(target<0) return;
        if(idx==candidates.size()) return;
        
        //include
        currentComb.push_back(candidates[idx]);
        helper(idx,target-candidates[idx],candidates,currentComb,combinations);
        
        //exclude
        currentComb.pop_back();
        helper(idx+1,target,candidates,currentComb,combinations);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>currentComb;
        vector<vector<int> >combinations;
        helper(0,target,candidates,currentComb,combinations);
        return combinations;
    }
};