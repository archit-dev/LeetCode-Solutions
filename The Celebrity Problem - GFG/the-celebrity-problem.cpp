// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    vector<vector<int>>m;
    bool knows(int a,int b){
        return m[a][b];
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        m = M;
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>=2){
            int p1 = st.top();
            st.pop();
            int p2 = st.top();
            st.pop();
            if(knows(p1,p2)){
                //p1 knows p2 ==> p1 is 
                //definitely not celeb
                st.push(p2);
            }else{
                //p2 knows p1==>p2 is not celeb
                st.push(p1);
            }
        }
        //after this, the elemnt left in the stack
        //is a potential celeb
        int potential = st.top();
        bool flag = true;
        for(int i=0;i<n;i++){
            if(i==potential) continue;
            //check if potential celeb matches conditions
            if(knows(potential,i)){
                //if pot knows anyone its not a celeb
                flag= false;
                break;
            }
            if(!knows(i,potential)) {
                //if i doesnt know poten, poten is not celeb
                flag= false;
                break;
            }
        }
        if(flag) return potential;
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends