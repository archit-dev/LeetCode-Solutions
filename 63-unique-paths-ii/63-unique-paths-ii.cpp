class Solution {
public:
    int solve(int crow,int ccol,int erow,int ecol,vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid){
        
        if(crow>erow || ccol>ecol) return 0;
        if(obstacleGrid[crow][ccol]==1) return 0;
        if(crow==erow && ccol==ecol) return 1;
        if(dp[crow][ccol]!=-1) return dp[crow][ccol];
        
        
        int right = solve(crow,ccol+1,erow,ecol,dp,obstacleGrid);
        int down = solve(crow+1,ccol,erow,ecol,dp,obstacleGrid);
        return dp[crow][ccol] = right+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector< vector<int> > dp(n,vector<int>(m,-1));
        return solve(0,0,n-1,m-1,dp,obstacleGrid);
    }
};