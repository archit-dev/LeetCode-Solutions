class Solution {
public:
    vector<vector<int>> solve(vector<int>& candidates,int n, int target){
        if(n<0 || target<0){
            vector<vector<int>> empty;
            return empty;
        }
        if(target==0){
            vector<vector<int>> notEmpty;
            vector<int>temp;
            notEmpty.push_back(temp);
            return notEmpty;
        }
        vector<vector<int>>ans;
        vector<vector<int>>include = solve(candidates,n,target-candidates[n]);
        vector<vector<int>>notInclude = solve(candidates,n-1,target);
        for(auto &it:include){
            it.push_back(candidates[n]);
            ans.push_back(it);
        }
        for(auto &it:notInclude){
            ans.push_back(it);
        }
        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return solve(candidates,candidates.size()-1,target);
    }
};