// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
private:
    void helper(vector<int>& arr,vector<int>&sum,int idx,int n,int currSum){
        if(idx==n){
            sum.push_back(currSum);
            return;
        }
        //exlude
        helper(arr,sum,idx+1,n,currSum);
        //include 
        helper(arr,sum,idx+1,n,currSum+arr[idx]);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        helper(arr,ans,0,N,0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends