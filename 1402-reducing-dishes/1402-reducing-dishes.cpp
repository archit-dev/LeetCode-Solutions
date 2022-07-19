class Solution {
public:
    int dp[501][501];
    
    int helper(vector<int>& arr,int ptr,int time){
        if(ptr==arr.size()){
            return 0;
        }
        if(dp[ptr][time] != -1) return dp[ptr][time];
        
        //exclude
        int exclude = helper(arr,ptr+1,time);
        //include
        int include = helper(arr,ptr+1,time+1)+(arr[ptr]*time);
        
        return dp[ptr][time] = max(exclude,include);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp,-1,sizeof dp);
        sort(satisfaction.begin(),satisfaction.end());
        return helper(satisfaction,0,1);
    }
};