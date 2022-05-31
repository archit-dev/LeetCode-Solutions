class Solution {
public:
    void bfsHelper(int x,int y,int n,vector<vector<int>>& isConnected,vector<int>&vis)
    {
        vis[x] = 1;
        vis[y] = 1;
        queue<pair<int,int> >Queue;
        Queue.push({x,y});
        while(!Queue.empty()){
            int currX = Queue.front().first;
            int currY = Queue.front().second;
            Queue.pop();
            for(int i=0;i<n;i++){
                if(vis[i]==0 && isConnected[currX][i]==1){
                    Queue.push({currX,i});
                    vis[i] = 1;
                }
            }
            for(int i=0;i<n;i++){
                if(vis[i]==0 && isConnected[currY][i]==1){
                    Queue.push({currY,i});
                    vis[i] = 1;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && visited[i]==0){
                    bfsHelper(i,j,n,isConnected,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};