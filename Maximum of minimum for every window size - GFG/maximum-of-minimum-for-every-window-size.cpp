// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        stack<pair<int,int>>s1,s2;
        vector<int>left(n,-1),right(n,n);
        //find nsl
        for(int i=0;i<n;i++){
            while(s1.empty()==false && s1.top().first>=arr[i]){
                s1.pop();
            }
            if(s1.empty()==false) left[i] = s1.top().second;
            s1.push({arr[i],i});
        }
        
        //nsr
        for(int i=n-1;i>=0;i--){
            while(s2.empty()==false && s2.top().first>=arr[i]){
                s2.pop();
            }
            if(s2.empty()==false) right[i] = s2.top().second;
            s2.push({arr[i],i});
        }
        
        //calculate the windowsize that it can be min in
        vector<int>windowSize(n,1);
        vector<int>ans(n,INT_MIN);
        for(int i=0;i<n;i++){
            windowSize[i] = right[i]-left[i]-1;
            ans[windowSize[i]-1] = max(arr[i],ans[windowSize[i]-1]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends