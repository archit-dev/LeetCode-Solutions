class Solution {
public:
    void reverseArr(vector<int>& arr,int low,int high){
        while(low<=high){
            swap(arr[low],arr[high]);
            low+=1;
            high-=1;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int pivot = n-2;
        //find the pivot element
        while(pivot>=0){
            if(nums[pivot]<nums[pivot+1]){
                break;
            }
            pivot--;
        }
        // cout<<pivot<<"v";
        
        if(pivot>=0){
            int greaterThanPivot = n-1;
            while(greaterThanPivot>pivot){
                if(nums[greaterThanPivot]>nums[pivot]){
                    swap(nums[greaterThanPivot],nums[pivot]);
                    break;
                }
                greaterThanPivot--;
            }
            // cout<<greaterThanPivot;
        }
        
        reverseArr(nums,pivot+1,n-1);
    }
};