class Solution {
public:
    int getIndexOfPivot(vector<int> & nums){
        int low = 0 , high = nums.size()-1;
        int n = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            int left = (mid + n -1 )%n;
            int right = (mid+1)%n;
            if(nums[low] < nums[high]) return low;
            if(nums[left]>=nums[mid] && nums[mid] <= nums[right]){
                return mid;
            }
            else{
                if(nums[low] <= nums[mid]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return 0;
    }
    
    int binarySearch(vector<int> & nums,int target,int low,int high){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else{
                if(nums[mid]<target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int idxPivot = getIndexOfPivot(nums); 
        int leftSearch = binarySearch(nums,target,0,idxPivot-1);
        if(leftSearch==-1) return binarySearch(nums,target,idxPivot,nums.size()-1);
        return leftSearch;
    }
};