class Solution {
public:
    void reverseArray(vector<int>& nums,int start,int end){
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        return;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int breakPoint = n-2;
        while(breakPoint>=0){
            if(nums[breakPoint] < nums[breakPoint+1]){
                break;
            }
            breakPoint--;
        }
        if(breakPoint>=0){
            int greaterThanBreakPoint = n-1;
            while(greaterThanBreakPoint>breakPoint){
                if(nums[greaterThanBreakPoint]>nums[breakPoint]){
                    swap(nums[greaterThanBreakPoint],nums[breakPoint]);
                    break;
                }
                greaterThanBreakPoint--;
            }
        }
        reverseArray(nums,breakPoint+1,n-1);
        return;
    }
};