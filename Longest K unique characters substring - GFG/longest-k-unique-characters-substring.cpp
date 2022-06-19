// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.size();
        unordered_map<char,int>alpha;
        int ans = -1;
        int low = 0 , high = 0;
        while(high<n){
            alpha[s[high]]+=1;
            if(alpha.size()==k){
                ans = max(ans, high-low+1);
                high++;     
            }else if(alpha.size()<k){
                high++;
            }else{
                while(low<=high && alpha.size()>k){
                    alpha[s[low]]-=1;
                    if(alpha[s[low]]==0){
                        alpha.erase(s[low]);
                    }
                    low++;
                }
                high++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends