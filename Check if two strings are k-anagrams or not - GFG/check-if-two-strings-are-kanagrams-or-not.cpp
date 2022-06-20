// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if(str1.size()!=str2.size()) return false;
        unordered_map<char,int> mp;
        for(char x:str2) mp[x]+=1;
        int diff = 0;
        for(char x:str1){
            if(mp.find(x)==mp.end()){
                diff+=1;
            }else{
                mp[x]-=1;
                if(mp[x]<0){
                    diff+=1;
                }
            }
        }
        return diff<=k;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends