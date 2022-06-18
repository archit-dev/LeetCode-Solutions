class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minIndex = 0;
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int left = (mid-1+n)%n;
            int right = (mid+1)%n;
            if(nums[low]<=nums[high]){
                minIndex = low;
                break;
            }
            if(nums[left]>nums[mid] && nums[mid]<nums[right]){
                minIndex = mid;
                break;
            }else{
                if(nums[low]<=nums[mid]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        //first perform binary search in ascending array
        low = minIndex, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else{
                if(nums[mid]<target){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        //perform binary search in descending array
        low = 0, high = minIndex-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else{
                if(nums[mid]<target){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};