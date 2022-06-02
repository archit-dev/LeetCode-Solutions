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
        helper(idx+1,target-candidates[idx],candidates,currentComb,combinations);
        
        //exclude
        currentComb.pop_back();
        int currentNum = candidates[idx];
        while(idx<candidates.size() && currentNum==candidates[idx]) idx++;
        helper(idx,target,candidates,currentComb,combinations);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>currentComb;
        vector<vector<int> >combinations;
        sort(candidates.begin(),candidates.end());
        helper(0,target,candidates,currentComb,combinations);
        return combinations;
    }
};