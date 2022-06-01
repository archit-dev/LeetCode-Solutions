class Solution {
public:
    void helper(vector<int>& nums,vector<int>& currentSubset,vector<vector<int> >& allSubsets,
               int idx,int n)
    {
        if(idx>=n){
            allSubsets.push_back(currentSubset);
            return;
        }
        
        //include
        currentSubset.push_back(nums[idx]);
        helper(nums,currentSubset,allSubsets,idx+1,n);
        
        //exclude
        currentSubset.pop_back();
        int currentElement = nums[idx];
        while(idx<n && currentElement==nums[idx]) idx++;
        helper(nums,currentSubset,allSubsets,idx,n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int> > allSubsets;
        vector<int> currentSubset;
        helper(nums,currentSubset,allSubsets,0,n);
        return allSubsets;
    }
};