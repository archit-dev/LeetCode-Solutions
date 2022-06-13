class Solution {
public:
    int solve(int currentIndex,int currentRow,int n, vector<vector<int>>& triangle, vector<vector<int>>& dp ){
        if(currentRow>n) return 0;
        if(dp[currentIndex][currentRow]!=-1) return dp[currentIndex][currentRow];
        
        int down = solve(currentIndex,currentRow+1,n,triangle,dp) + triangle[currentRow][currentIndex];
        int right = solve(currentIndex+1,currentRow+1,n,triangle,dp) + triangle[currentRow][currentIndex];
        
        return dp[currentIndex][currentRow] = min(down,right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector< vector<int> > dp(triangle[n-1].size()+1,vector<int>(n+1,-1));
        return solve(0,0,n-1,triangle,dp);
    }
};