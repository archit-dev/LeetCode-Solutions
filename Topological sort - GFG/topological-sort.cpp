// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> graph[]) 
	{
	    vector<int>indegree(V,0);
	    //fill up the indegree array
	    for(int node=0;node<V;node++){
	        for(auto nbr:graph[node]){
	            indegree[nbr]++;
	        }
	    }
	    //add all the 0 indegree elements to a queue
	    queue<int>Queue;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) Queue.push(i);
	    }
	    int countOfVertices = 0;
	    vector<int>ans;
	    while(!Queue.empty()){
	        int node = Queue.front();
	        Queue.pop();
	        ans.push_back(node);
	        countOfVertices++;
	        //now decrement the indegree of all the nbrs
	        for(auto nbr:graph[node]){
	            indegree[nbr]--;
	            if(indegree[nbr]==0) Queue.push(nbr);
	        }
	    }
	    //if(countOfVertices!=V) cout<<"Toposort unsuccessful";
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