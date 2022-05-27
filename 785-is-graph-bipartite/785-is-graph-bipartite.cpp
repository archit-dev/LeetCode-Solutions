class Solution {
public:
    bool bipartiteBFS(int node,int color,vector<vector<int>>& graph,vector<int>& colors){
        queue<pair<int,int>>Queue;
        colors[node] = color;
        Queue.push({node,color});
        while(!Queue.empty()){
            int currentNode = Queue.front().first;
            int currentColor = Queue.front().second;
            Queue.pop();
            for(auto nbr:graph[currentNode]){
                //if the nbr is not visited
                if(colors[nbr]==-1){
                    colors[nbr]=!currentColor;
                    Queue.push({nbr,colors[nbr]});
                }
                //else if it is visited and has same color 
                //as the current node
                else if(colors[nbr]!=-1 && colors[nbr]==currentColor){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>colors(v,-1);
        for(int i=0;i<v;i++){
            if(colors[i]==-1){
                //if the graph is not bipartite for any of the 
                //components, return false;
                if(!bipartiteBFS(i,0,graph,colors)){
                    return false;
                }
            }
        }
        //the graph is bipartite and return true
        return true;
    }
};