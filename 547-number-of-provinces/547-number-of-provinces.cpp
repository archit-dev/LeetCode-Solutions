class Solution {
public:
    void bfsHelper(int x,int y,int n,vector<vector<int>>& isConnected,vector<vector<int>>& vis)
    {
        vis[x][y] = 1;
        vis[y][x] = 1;
        queue<pair<int,int> >Queue;
        Queue.push({x,y});
        while(!Queue.empty()){
            int currX = Queue.front().first;
            int currY = Queue.front().second;
            Queue.pop();
            for(int i=0;i<n;i++){
                if(vis[currX][i]==0 && isConnected[currX][i]==1){
                    Queue.push({currX,i});
                    vis[currX][i] = 1;
                    vis[i][currX] = 1;
                }
            }
            for(int i=0;i<n;i++){
                if(vis[currY][i]==0 && isConnected[currY][i]==1){
                    Queue.push({currY,i});
                    vis[currY][i] = 1;
                    vis[i][currY] = 1;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int> > visited(n,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && visited[i][j]==0){
                    bfsHelper(i,j,n,isConnected,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};