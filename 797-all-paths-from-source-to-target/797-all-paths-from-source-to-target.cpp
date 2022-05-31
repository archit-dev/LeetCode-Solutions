class Solution {
public:
    void dfsHelper(int node,vector<vector<int>>& graph,
                                  vector<vector<int>>& paths,vector<int>& currentPath)
    {
        if(node==graph.size()-1){
            currentPath.push_back(node);
            paths.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        currentPath.push_back(node);
        for(auto nbr:graph[node]){
            dfsHelper(nbr,graph,paths,currentPath);
        }
        currentPath.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int> > paths; 
        vector<int>currentPath;
        dfsHelper(0,graph,paths,currentPath);
        return paths;
    }
};