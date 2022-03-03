class Solution {
public:
    int merge(vector<int>& nums,vector<int>& temp,int low,int mid,int high){
        int ptr1 = low , ptr2 = mid , ptr3 = low;
        int count = 0;
        while(ptr1<mid){
            while(ptr2<=high && nums[ptr1]>(long long)2*nums[ptr2]){
                ptr2++;
            }
            count += ptr2 - mid;
            ptr1++;
        }
        ptr1 = low;
        ptr2 = mid;
        while(ptr1 < mid && ptr2 <=high){
            if(nums[ptr1]<nums[ptr2]){
                temp[ptr3++] = nums[ptr1++];
            }
            else{
                temp[ptr3++] = nums[ptr2++];
            }
        }
        while(ptr1<mid) temp[ptr3++] = nums[ptr1++];
        while(ptr2<=high) temp[ptr3++] = nums[ptr2++];
        for(int i=low;i<=high;i++){
            nums[i] = temp[i];
        }
        return count;
    }
    
    int mergeSort(vector<int>& nums,vector<int>& temp,int low,int high){
        int countPairs = 0;
        if(low<high){
            int mid = low+(high-low)/2;
            countPairs += mergeSort(nums,temp,low,mid);
            countPairs += mergeSort(nums,temp,mid+1,high);
            countPairs +=merge(nums,temp,low,mid+1,high);
        }
        return countPairs;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums,temp,0,n-1);
    }
};