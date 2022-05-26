// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool dfsCycle(int node, vector<bool> & visitedSoFar,
                vector<bool> & visitedOnThisPath, 
                vector<int> graph[]){
      
      visitedSoFar[node] = true;
      visitedOnThisPath[node] = true;
      
      for(auto nbr:graph[node]){
          if(!visitedSoFar[nbr]){
              if(dfsCycle(nbr,visitedSoFar,visitedOnThisPath,graph)){
                  return true;
              }
          }else if(visitedSoFar[nbr] && visitedOnThisPath[nbr]){
              return true;
          }
      }
      
      //while coming back, use backtracking to unmark
      //visited on this path boolean array
      visitedOnThisPath[node] = false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visitedSoFar(V,false);
        vector<bool> visitedOnThisPath(V,false);
        for(int i=0;i<V;i++){
            if(!visitedSoFar[i]){
                if(dfsCycle(i,visitedSoFar,visitedOnThisPath,adj)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends