class Solution {
public:
    int binarySearch(vector<int>& nums,int low,int high,int target){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else{
                if(nums[mid]<target){
                    low= mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) return nums[0]==target ? 0 : -1;
        int low = 0 , high = nums.size()-1;
        int n = nums.size();
        int pivot = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int left = (mid-1+n)%n;
            int right = (mid+1)%n;
            if(nums[low]<nums[high]){
                pivot = low;
                break;
            }
            if(nums[mid]<nums[left] && nums[mid]<nums[right]){
                pivot = mid;
                break;
            }else{
                if(nums[low]<=nums[mid]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        // cout<<pivot<<"\n";
        int ans = binarySearch(nums,0,pivot-1,target);
        if(ans==-1) ans = binarySearch(nums,pivot,n-1,target);
        return ans;
    }
};