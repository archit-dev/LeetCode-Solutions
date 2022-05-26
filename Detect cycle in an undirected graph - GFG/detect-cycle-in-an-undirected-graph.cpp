// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool cycleDFS(int node,int parent,vector<int> graph[],vector<bool>& visited){
        visited[node] = true;
        for(auto nbr:graph[node]){
            if(visited[nbr]==false){
                //not visited
                if(cycleDFS(nbr,node,graph,visited)) return true;
            }
            else if(visited[nbr]==true && nbr!=parent){
                //visited and its not the current node's parent
                //then there exists a cycle
                return true;
            }
        }
        return false;
    }
    
    bool cycleBFS(int node,int parent,vector<int> graph[],vector<bool>& visited){
        visited[node] = true;
        queue<pair<int,int> > Queue;
        Queue.push({node,parent});
        while(!Queue.empty()){
            int currentNode = Queue.front().first;
            int currentParent = Queue.front().second;
            Queue.pop();
            for(auto nbr : graph[currentNode]){
                //if neighbour is not visited
                if(visited[nbr]==false){
                    Queue.push({nbr,currentNode});
                    visited[nbr]=true;
                }else if(visited[nbr]==true && nbr!=currentParent){
                    //you reach a visited node and 
                    //it is not the parent of the current node
                    return true;
                }
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // if(cycleDFS(i,-1,adj,visited)) return true;
                if(cycleBFS(i,-1,adj,visited)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends