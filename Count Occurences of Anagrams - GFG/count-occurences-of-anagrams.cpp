// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char,int> mp1,mp2;
	    for(char x:pat)mp2[x]+=1;
	    int low = 0, high = 0 , count = 0;
	    int reqMatch = pat.size(), curMatch = 0;
	    while(high<txt.size()){
	        if(mp2.find(txt[high])==mp2.end()){
	            low = high+1; 
	            mp1.clear();
	            curMatch=0;
	        }else{
	            mp1[txt[high]]+=1;
    	        curMatch+=1; 
    	        while(low<=high && mp1[txt[high]]>mp2[txt[high]]){
    	            mp1[txt[low]]-=1; 
    	            curMatch-=1;
    	            low++;
    	        }
    	        if(curMatch==reqMatch){
    	            count+=1;
    	           // cout<<"d\n";
    	        }
	        }
	        high+=1;
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