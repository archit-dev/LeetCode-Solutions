// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if(a.size()!=b.size()){
            return false;
        }
        int a_[26]={0};
        int b_[26]={0};
        for(int i=0;i<a.size();i++){
            a_[a[i]-'a']++;
            b_[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a_[i]!=b_[i]) return false;
        }
        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends