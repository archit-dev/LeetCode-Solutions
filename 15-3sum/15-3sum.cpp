class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int low = i+1, high = n-1;
            while(low<high){
                int threeSum = nums[i]+nums[low]+nums[high];
                
                if(threeSum<0) low+=1;
                
                else if(threeSum>0) high-=1;
                
                else{
                    vector<int> temp = {nums[i],nums[low],nums[high]};
                    ans.push_back(temp);
                    
                    low+=1;
                    high-=1;
                    
                    while(low<high && nums[low]==nums[low-1]) low+=1;
                    while(low<high && nums[high]==nums[high+1]) high-=1;
                }
                
            }
        }
        return ans;
    }
};