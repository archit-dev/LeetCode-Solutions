// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        int low = 0 , high = 0;
        vector<int>ans;
        unordered_map<int,int> mp;
        while(high<n){
            if(high-low==k){
                mp[A[low]]-=1;
                if(mp[A[low]]==0) mp.erase(A[low]);
                low++;
            }
            mp[A[high]]+=1;
            if(high>=k-1){
                ans.push_back(mp.size());
            }
            high++;
        }
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