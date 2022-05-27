class Solution {
public:
    bool bipartiteDFS(int node,int color,vector<vector<int>>& graph,vector<int>& colors){
        colors[node] = color;
        for(auto nbr : graph[node]){
            //if unvisited
            if(colors[nbr]==-1){
                if(!bipartiteDFS(nbr,!color,graph,colors)){
                    return false;
                }
            }
            //if visited and has same color
            else if(colors[nbr]!=-1 && colors[nbr]==color){
                return false;
            }
        }
        //if no neighbours have same colors, graph is bipartite
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>colors(v,-1);
        for(int i=0;i<v;i++){
            if(colors[i]==-1){
                if(!bipartiteDFS(i,0,graph,colors)){
                    return false;
                }
            }
        }
        return true;
    }
};