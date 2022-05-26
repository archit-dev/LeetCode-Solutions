// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    void bfsHelper(int node,vector<int>graph[],
    vector<bool>& visited,vector<int>& traversal)
    {
        visited[node]= true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            traversal.push_back(current);
            for(auto nbr:graph[current]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> traversal;
        vector<bool> visited(V,false);
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
        //         bfsHelper(i,adj,visited,traversal);
        //     }
        // }
        bfsHelper(0,adj,visited,traversal);
        return traversal;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends