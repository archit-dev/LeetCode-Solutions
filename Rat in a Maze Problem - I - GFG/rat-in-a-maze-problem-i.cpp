// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void solve(vector<string>& paths,string &currentPath,int cr,int cc,
            vector<vector<int>> & maze,int n)
    {
        if(cr>=n || cr<0 || cc>=n || cc<0 || maze[cr][cc]==0) return;
        
        if(cr==n-1 && cc==n-1) {
            paths.push_back(currentPath);
            return;
        }
        maze[cr][cc] = 0;
        currentPath.push_back('U');
        solve(paths,currentPath,cr-1,cc,maze,n);
        currentPath.pop_back();
        
        currentPath.push_back('D');
        solve(paths,currentPath,cr+1,cc,maze,n);
        currentPath.pop_back();
        
        currentPath.push_back('L');
        solve(paths,currentPath,cr,cc-1,maze,n);
        currentPath.pop_back();
        
        currentPath.push_back('R');
        solve(paths,currentPath,cr,cc+1,maze,n);
        currentPath.pop_back();
        
        maze[cr][cc] = 1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> allPaths;
        string s;
        solve(allPaths,s,0,0,m,n);
        return allPaths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends