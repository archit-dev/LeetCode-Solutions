// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int low = 0 , high = 0 , len = -1;
        unordered_map<char,int> mp;
        while(high<s.size()){
            mp[s[high]]+=1;
            while(low<=high && mp.size()>k){
                mp[s[low]]-=1;
                if(mp[s[low]]==0) mp.erase(s[low]);
                low++;
            }
            if(mp.size()==k){
                len = max(len,high-low+1);
            }
            high+=1;
        }
        return len;
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