// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoSortDFS(int node,vector<int>graph[],vector<bool>& visited,stack<int>& topo){
	    visited[node] = true;
	    for(auto nbr:graph[node]){
	        if(!visited[nbr]){
	            topoSortDFS(nbr,graph,visited,topo);
	        }
	    }
	    topo.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> topo;
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            topoSortDFS(i,adj,visited,topo);
	        }
	    }
	    vector<int>ans;
	    while(!topo.empty()){
	        ans.push_back(topo.top());
	        topo.pop();
	    }
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends