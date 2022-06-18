// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        int low = max(0,k-m), high = min(n,k);
        while(low<=high){
            int cut1 = low + (high-low)/2;
            int cut2 = k - cut1;
            
            int leftA = cut1 > 0 ? arr1[cut1-1] : INT_MIN;
            int leftB = cut2 > 0 ? arr2[cut2-1] : INT_MIN;
            
            int rightA = cut1 < n ? arr1[cut1] : INT_MAX;
            int rightB = cut2 < m ? arr2[cut2] : INT_MAX;
            
            if(leftA <=rightB && leftB <=rightA){
                return max(leftA,leftB);
            }
            else if(leftA > rightB){
                high = cut1 - 1;
            }else{
                low = cut1 + 1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends