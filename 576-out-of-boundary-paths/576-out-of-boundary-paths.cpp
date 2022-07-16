class Solution {
public:
    long long dp[51][51][51];
    int mod = 1e9+7;
    int helper(int m, int n, int maxMove, int cr, int cc){
        if(maxMove==0) return 0;
        if(dp[cr][cc][maxMove]!=-1) return dp[cr][cc][maxMove];
        long long dx[]={1,-1,0,0};
        long long dy[]={0,0,1,-1};
        long long count = 0;
        for(int i=0;i<4;i++){
            int newX = dx[i]+cr;
            int newY = dy[i]+cc;
            if(newX <0 || newX >= m || newY <0 || newY>=n) count+=1;
            else{
                count=(helper(m,n,maxMove-1,newX,newY)+count)%mod;
            }
        }
        return dp[cr][cc][maxMove] = count;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return helper(m,n,maxMove,startRow,startColumn);
    }
};