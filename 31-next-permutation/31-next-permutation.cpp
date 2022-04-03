class Solution {
public:
    void reverseArr(vector<int>&nums,int start,int end){
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = n-2;
        while(breakPoint>=0){
            if(nums[breakPoint]<nums[breakPoint+1]){
                break;
            }
            breakPoint--;
        }
        int nextGreaterToBreakPoint = n-1;
        if(breakPoint>=0){
            while(nextGreaterToBreakPoint>breakPoint){
                if(nums[nextGreaterToBreakPoint]>nums[breakPoint]){
                    swap(nums[nextGreaterToBreakPoint],nums[breakPoint]);
                    break;
                }
                nextGreaterToBreakPoint-=1;
            }
        }
        reverseArr(nums,breakPoint+1, n-1);
    }
};