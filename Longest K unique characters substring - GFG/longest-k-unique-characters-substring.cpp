// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestAtMaxKSubstr(string &s,int k){
        unordered_map<char,int>mp;
        int len = -1, low = 0, high = 0;
        while(high<s.size()){
            mp[s[high]]+=1;
            while(low<=high && mp.size()>k){
                mp[s[low]]-=1;
                if(mp[s[low]]==0) mp.erase(s[low]);
                low++;
            }
            if(mp.size()==k) len = max(len,high-low+1);
            high++;
        }
        return len;
    }
    int longestKSubstr(string s, int k) {
        return longestAtMaxKSubstr(s,k);
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