class Solution {
public:
    void dfsHelper(int node,vector<int>&visited,vector<vector<int>>&isConnected){
        visited[node] = 1;
        for(int i=0;i<isConnected.size();i++){
            int currentNbr = isConnected[node-1][i];
            if(!visited[i+1] && currentNbr==1){
                dfsHelper(i+1,visited,isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n+1,0);
        int countOfProvinces=0;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfsHelper(i,visited,isConnected);
                countOfProvinces++;
            }
        }
        return countOfProvinces;
    }
};