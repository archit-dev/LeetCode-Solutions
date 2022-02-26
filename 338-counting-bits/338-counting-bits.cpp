class Solution {
public:
    int numberOfOnes(int x,vector<int>&nums){
        if(x==0) return 0;
        if(x==1) return 1;
        if(nums[x]!=-1) return nums[x];
        return nums[x] = numberOfOnes((x>>1),nums) + (x&1);
    }
    
    vector<int> countBits(int n) {
        vector<int>nums(n+1,-1);
        for(int i=0;i<=n;i++){
            nums[i] = numberOfOnes(i,nums);
        }
        return nums;
    }
};