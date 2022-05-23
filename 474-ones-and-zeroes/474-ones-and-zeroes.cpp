class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>& strs,int currentIndex,int m,int n){
        if(currentIndex<0) return 0;
        if(m<=0 && n<=0) return 0;
        if(dp[currentIndex][m][n]!=-1) return dp[currentIndex][m][n];
        int m_ = m;
        int n_ = n;
        for(char x:strs[currentIndex]){
            if(x=='0') m_--;
            else n_--;
        }
        int include = INT_MIN, exclude = INT_MIN;
        if(m_>=0 && n_>=0)
            include = 1 + solve(strs,currentIndex-1,m_,n_);
        exclude = solve(strs,currentIndex-1,m,n);
        return dp[currentIndex][m][n] = max(include,exclude);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,strs.size()-1,m,n);
    }
};