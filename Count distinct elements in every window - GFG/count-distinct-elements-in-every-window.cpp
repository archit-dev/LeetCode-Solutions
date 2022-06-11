// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        int ptr = 0;
        unordered_map<int,int>mp;
        while(ptr<k){
            mp[A[ptr]]+=1;
            ptr++;
        }
        vector<int>ans;
        int ptr1 = 0;
        while(ptr<n){
            int currSize = mp.size();
            ans.push_back(currSize);
            if(mp[A[ptr1]]==1){
                mp.erase(A[ptr1]);
            }else{
                mp[A[ptr1]]-=1;
            }
            mp[A[ptr]]+=1;
            ptr++;
            ptr1++;
        }
        int currSize = mp.size();
        ans.push_back(currSize);
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends