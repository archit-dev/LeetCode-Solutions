//running code
class Solution {
    public long maxAlternatingSum(int[] nums) 
    {
        int n = nums.length;
        long dp[][] = new long[n+1][2];
        for(int i=0;i<n+1;i++)
        {
            Arrays.fill(dp[i],-1);
        }
        
        return (func(nums,0,0,dp));   
    }
    
    static long func(int nums[],int p,int count,long dp[][])
    {
        if(p>=nums.length)
        {
            return 0;
        }
        if(dp[p][count%2]==-1)
        {
            long pick=0,not=0;
            if(count%2==0)
            {
                pick = nums[p] + func(nums,p+1,count+1,dp);
                not = func(nums,p+1,count,dp);
            }

            if(count%2==1)
            {
                pick = func(nums,p+1,count+1,dp) - nums[p] ;
                not = func(nums,p+1,count,dp);
            }

            dp[p][count%2] = Math.max(pick,not);
        }
        
        return dp[p][count%2];
        
    }
}