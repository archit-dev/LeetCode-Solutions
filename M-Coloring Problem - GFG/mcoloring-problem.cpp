// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int node, vector<int>& colors,int col){
    for(int i=0;i<101;i++){
        if(i!=node && graph[node][i]==1 && colors[i]==col) return false;
    }
    return true;
}

bool color(bool graph[101][101], int node, vector<int>& colors,int m, int n){
    if(node==n) return true;
    for(int i=1;i<=m;i++){
        if(isSafe(graph,node,colors,i)){
            colors[node] = i;
            if(color(graph,node+1,colors,m,n)){
                return true;
            }
            colors[node] = 0;
            
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int>colors(n,0);
    if(color(graph,0,colors,m,n)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends