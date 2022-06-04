// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isValid(int x,int y,int n){
        if(x>=0 && x<n && y>=0 && y<n) return true;
        return false;
    }
    
    void solve(vector<string> &paths,string currentPath,
                int cr,int cc,vector<vector<int>>& maze,int n)
    {
        if(cr==n-1 && cc==n-1){
            paths.push_back(currentPath);
            return;
        }
        if(maze[cr][cc]==0) return;
        maze[cr][cc] = 0;
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        string possPaths = "DLRU";
        for(int i=0;i<4;i++){
            int newX = cr+dx[i];
            int newY = cc+dy[i];
            if(isValid(newX,newY,n) && maze[newX][newY]==1){
                solve(paths,currentPath+possPaths[i],newX,newY,maze,n);
            }
        }
        maze[cr][cc] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>paths;
        solve(paths,"",0,0,m,n);
        return paths;
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