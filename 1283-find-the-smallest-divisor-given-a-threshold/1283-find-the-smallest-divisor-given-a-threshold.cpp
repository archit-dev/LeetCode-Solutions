class Solution {
public:
    bool checkForCondition(vector<int>&nums,int threshold,int ans){
        int sum = 0;
        for(int &x : nums){
            sum+=x/ans;
            if(x%ans!=0) sum+=1;
        }
        if(sum<=threshold) return true;
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = nums[0];
        for(int &x:nums) high = max(x,high);
        int potentialAns = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            bool status = checkForCondition(nums,threshold,mid);
            if(status){
                potentialAns = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return potentialAns;
    }
};