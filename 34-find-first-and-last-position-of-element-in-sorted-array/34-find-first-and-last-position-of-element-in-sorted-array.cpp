class Solution {
public:
    int findLowRange(vector<int>& nums,int target){
        int low = 0, high = nums.size()-1, ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                ans = mid;
                high = mid - 1;
            }else{
                if(nums[mid]<target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return ans;
    }
    
    int findHighRange(vector<int>& nums,int target){
        int low = 0, high = nums.size()-1, ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                ans = mid;
                low = mid + 1;
            }else{
                if(nums[mid]<target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = findLowRange(nums,target);
        int high = findHighRange(nums,target);
        vector<int> ans(2);
        ans[0] = low;
        ans[1] = high;
        return ans;
    }
};