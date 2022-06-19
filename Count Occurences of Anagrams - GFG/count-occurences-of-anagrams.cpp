// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool same(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
	int search(string pat, string txt) {
	    int alpha1[26]={0}, alpha2[26]={0};
	    for(char x:pat) alpha1[x-'a'] +=1;
	    int low = 0 , high = 0, n = txt.size(),count = 0, k = pat.size();
	    while(high<n){
	        alpha2[txt[high]-'a']+=1;
	        if(high-low==k){
	            alpha2[txt[low]-'a']-=1;
	            low++;
	        }
	        if(high>=k-1){
	            if(same(alpha1,alpha2)){
	                count+=1;
	            }
	        }
	        high++;
	    }
	    return count;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends