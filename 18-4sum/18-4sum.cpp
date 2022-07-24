class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // long long fourSum = target;
        for(int i=0;i<n-3;){
            for(int j=i+1;j<n;){
                int low = j+1, high = n-1;
                long long tgt = nums[i]+nums[j];
                while(low<high){
                    long long fourSum=(nums[low]+nums[high]);
                    if(fourSum+tgt == target){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low+=1;
                        high-=1;
                        while(low<high && nums[low]==nums[low-1]) low+=1;
                        while(low<high && nums[high]==nums[high+1]) high-=1;
                    }
                    else if(fourSum+tgt<target){
                        low+=1;
                    }
                    else{
                        high-=1;
                    }
                }
                j+=1;
                while(j<n && nums[j-1]==nums[j])j+=1;
            }
            i+=1;
            while(i<n && nums[i-1]==nums[i]) i+=1;
        }
        
        return ans;
    }
};