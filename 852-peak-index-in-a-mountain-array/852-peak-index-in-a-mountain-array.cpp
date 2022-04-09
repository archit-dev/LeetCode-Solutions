class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        int n = arr.size();
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int left = (mid-1+n)%n;
            int right = (mid+1)%n;
            if(arr[left] < arr[mid]  && arr[mid] > arr[right]){
                ans = mid; 
                break; 
            }else{
                //move towards the side which is sorted in the ascending order
                if(left==n-1 || arr[left] < arr[mid]){ 
                    low = mid + 1;
                }else if(right==0 || arr[left] > arr[mid]){ 
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};