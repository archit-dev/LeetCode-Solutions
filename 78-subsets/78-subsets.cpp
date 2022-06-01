class Solution {
public:
    void solve(vector<int>& nums,int idx,int n,vector<int>currentSubset,vector<vector<int>>& allSubsets)
    {
        if(idx==n){
            allSubsets.push_back(currentSubset);
            return;
        }    
        //include
        currentSubset.push_back(nums[idx]);
        solve(nums,idx+1,n,currentSubset,allSubsets);
        //exclude
        currentSubset.pop_back();
        solve(nums,idx+1,n,currentSubset,allSubsets);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>currentSubset;
        vector<vector<int>>allSubsets;
        solve(nums,0,nums.size(),currentSubset,allSubsets);
        return allSubsets;
    }
};