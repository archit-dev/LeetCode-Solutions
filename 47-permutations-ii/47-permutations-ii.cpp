class Solution {
public:
    void permute(vector<int>& nums,vector<vector<int>>& permutations,int idx,int n){
        if(idx==n){
            permutations.push_back(nums);
            return;
        }
        unordered_set<int>uniqueNums;
        for(int i=idx;i<n;i++){
            if(uniqueNums.find(nums[i])!=uniqueNums.end()) continue;
            //if the element is encountered for the first time
            //at this position
            uniqueNums.insert(nums[i]);
            swap(nums[i],nums[idx]);
            permute(nums,permutations,idx+1,n);
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >permutations;
        int n = nums.size();
        permute(nums,permutations,0,n);
        return permutations;
    }
};