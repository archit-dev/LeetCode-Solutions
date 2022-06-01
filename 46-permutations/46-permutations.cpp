class Solution {
public:
    void permuteHelper(vector<int>& nums,int idx,int n,vector<vector<int> >& permutations){
        if(idx==n){
            permutations.push_back(nums);
            return;
        }
        
        //from a particular index, permute till the end
        for(int i=idx;i<n;i++){
            //bring the i-th element to the current position
            swap(nums[i],nums[idx]);
            //permute for the next indices
            permuteHelper(nums,idx+1,n,permutations);
            //backtracking step to reorder the array
            swap(nums[idx],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> >permutations;
        permuteHelper(nums,0,n,permutations);
        return permutations;
    }
};