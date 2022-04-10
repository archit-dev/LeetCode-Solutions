class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int low = 0 ;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0){
                if(nums[mid+1]<nums[mid]) return mid;
                else return mid+1;
            }
            if(mid==n-1){
                if(nums[mid-1]<nums[mid]) return mid;
                else return mid-1;
            }
            int left = nums[mid-1];
            int right = nums[mid+1];
            if(nums[mid]>left && nums[mid]>right) return mid;
            else{
                if(left<=nums[mid]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};