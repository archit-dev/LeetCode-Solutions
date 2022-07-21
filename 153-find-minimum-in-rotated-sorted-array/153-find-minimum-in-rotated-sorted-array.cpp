class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size()-1, n = high+1;
        int pivot = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            int left = (mid-1+n)%n;
            int right = (mid+1)%n;
            if(nums[low]<=nums[high]){
                pivot = low;
                break;
            }
            if(nums[mid]<nums[left] && nums[mid]<nums[right]){
                pivot = mid;
                break;
            }
            else{
                if(nums[low]<=nums[mid]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return nums[pivot];
    }
};