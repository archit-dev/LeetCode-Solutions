class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    
    int bfsHelper(int cr,int cc,int n,int m,vector<vector<int>>& grid,
                  vector<vector<bool>>& visited)
    {
        visited[cr][cc] = 1;
        queue<pair<int,int> >Queue;
        Queue.push({cr,cc});
        int cells = 0;
        bool canReachBoundary = false;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!Queue.empty()){
            int x = Queue.front().first;
            int y = Queue.front().second;
            Queue.pop();
            cells++;
            if(x==0 || y==0 || x==n-1 || y==m-1) canReachBoundary = true;
            for(int i=0;i<4;i++){
                int newX = dx[i]+x;
                int newY = dy[i]+y;
                if(isValid(newX,newY,n,m) && !visited[newX][newY] && grid[newX][newY]==1){
                    visited[newX][newY] = true;
                    Queue.push({newX,newY});
                }
            }
        }
        if(canReachBoundary) return 0;
        return cells;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> >visited(n,vector<bool>(m,0));
        int ans = 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans+=bfsHelper(i,j,n,m,grid,visited);
                }
            }
        }
        return ans;
    }
};