// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public: 
  int solve(int nums[],int n,int sum1,int total,vector<vector<int>>&dp){
        if(n==0) return abs(total-sum1-sum1);
        if(dp[n][sum1]!=-1) return dp[n][sum1];
        int left = solve(nums,n-1,sum1+nums[n-1],total,dp);
        int right = solve(nums,n-1,sum1,total,dp);
        return dp[n][sum1]= min(left,right);
    }
	int minDifference(int arr[], int n)  {
        int total=0;
        for(int i=0;i<n;i++) total+=arr[i];
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        return solve(arr,n,0,total,dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends