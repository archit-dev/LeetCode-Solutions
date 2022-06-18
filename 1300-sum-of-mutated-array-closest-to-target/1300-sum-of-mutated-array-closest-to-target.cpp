class Solution {
    private:
    int helper(vector<int>& arr,int tgt,int mid){
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid){
                sum+=mid;
            }else{
                sum+=arr[i];
            }
        }
        return sum;
    }
    public:
    int findBestValue(vector<int>& arr, int target) {
        int ans = 0;
        int low = 0;
        int high = *max_element(arr.begin(),arr.end());
        int prevDiff = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = helper(arr,target,mid);
            int potential = abs(sum - target);
            if(potential<prevDiff){
                ans = mid;
                prevDiff = potential;
            }else if(potential==prevDiff){
                ans = min(ans,mid);
            }
            if(sum>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
            
    }
};