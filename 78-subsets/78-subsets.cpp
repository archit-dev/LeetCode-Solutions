class Solution {
public:
    vector<vector<int>> solve(vector<int>&nums,int curr,int n){
        if(curr>n){
            vector<vector<int>> ans;
            vector<int>temp;
            ans.push_back(temp);
            return ans;
        }
            
        vector<vector<int> > otherSubsets = solve(nums,curr+1,n);
        vector<vector<int> > currentAns;
        for(int i=0;i<otherSubsets.size();i++){
            currentAns.push_back(otherSubsets[i]);
            otherSubsets[i].push_back(nums[curr]);
            currentAns.push_back(otherSubsets[i]);
        }
        return currentAns;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};