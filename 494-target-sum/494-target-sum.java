class Solution {
    public int findTargetSumWays(int[] nums, int target) {
       if(nums.length ==1 && nums[0] != Math.abs(target)){
           return 0;
       }
        int req =0 ;
        for(int x:nums){
            req+=x;
        }
        if(req < target || (req + target) % 2 != 0)
            return 0;
        int n = nums.length;
        
        
        int sum = (target + req) / 2;
        int dp[][] = new int[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else if(i==0){
                    dp[i][j] = 0;
                }else if(j==0){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] =dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
        
        
        
        
    }
}